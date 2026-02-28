#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

/** Get the value of the index-th node. If index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* curr = obj->head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->val;
}

/** Add a node of value val before the first element of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj->size == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    Node* curr = obj->head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    obj->size++;
}

/** Add a node of value val before the index-th node. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

/** Delete the index-th node. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node* temp;
    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) curr = curr->next;
        temp = curr->next;
        curr->next = curr->next->next;
    }
    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}