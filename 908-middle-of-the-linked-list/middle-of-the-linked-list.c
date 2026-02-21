/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    // If the list is empty or has only one node, the answer is the head itself.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Fast pointer moves twice as fast as the slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // Moves 1 step
        fast = fast->next->next; // Moves 2 steps
    }

    // When fast reaches the end, slow is exactly at the middle
    return slow;
}