#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    // If the list is empty or has only one node, no cycle is possible
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move fast pointer by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // The Tortoise
        fast = fast->next->next;    // The Hare

        // If they meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If the fast pointer hits the end (NULL), no cycle exists
    return false;
}