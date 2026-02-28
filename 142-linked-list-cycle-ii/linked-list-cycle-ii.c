/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Determine if a cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Moves 1 step
        fast = fast->next->next;    // Moves 2 steps
        
        if (slow == fast) {
            // Step 2: Find the entry point of the cycle
            struct ListNode *entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return NULL; // No cycle found
}