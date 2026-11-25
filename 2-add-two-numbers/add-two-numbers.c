/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int c=0;
    struct ListNode newhead = {0,NULL};
    struct ListNode *t = &newhead;
    while(c || l1 || l2){
        if(l1 && l2){
            c += l1-> val + l2-> val;
            l1 = l1-> next;
            l2 = l2->next;
        }
        else if(l1){
            c += l1-> val;
            l1 = l1-> next;
        }
        else if(l2){
            c += l2->val;
            l2 = l2-> next;
        }

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode -> val = c%10;
        newNode -> next = NULL;
        
        t-> next = newNode;
        t = t-> next;
        c = c/10;
        
    }
    return newhead.next;
}