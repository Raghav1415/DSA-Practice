/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // 1. Create a dummy node to act as a placeholder before the head
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    // 2. Traverse the list
    while (current->next != NULL) {
        if (current->next->val == val) {
            // 3. Match found! Snip the connection.
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            
            // In a real-world C scenario, you'd free(temp) here.
            // On LeetCode, memory management requirements vary, 
            // but freeing is the "Master" way to do it.
            free(temp); 
        } else {
            // 4. No match, just move to the next node
            current = current->next;
        }
    }

    // 5. Return the actual head (which is dummy.next)
    return dummy.next;
}