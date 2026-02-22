/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    // 1. Initialize our tracking pointers to NULL 
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    
    // 2. Traverse the list until we hit the end (NULL) 
    while (head != NULL) {
        // Step A: Save the next node before we overwrite the pointer 
        next = head->next; 
        
        // Step B: Actually reverse the pointer to face backwards 
        head->next = prev; 
        
        // Step C: Shift 'prev' forward to the current node 
        prev = head; 
        
        // Step D: Shift 'head' forward to the saved next node 
        head = next; 
    }
    
    // 3. Once the loop ends, 'head' is NULL, and 'prev' is pointing to the 
    // new front of the list. We assign head to prev and return it. [cite: 455, 456, 457]
    head = prev;
    return head;
}