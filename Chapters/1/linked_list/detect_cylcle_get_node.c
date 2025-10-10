#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a singly linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to find the starting node of the loop
struct ListNode* getStartingNode(struct ListNode* head, struct ListNode* slowPtr) {
    struct ListNode* temp = head;

    while (slowPtr != temp) {
        temp = temp->next;
        slowPtr = slowPtr->next;
    }

    return temp; // Starting node of the cycle
}

// Function to detect a loop and return the starting node if one exists
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected, find the starting node
            return getStartingNode(head, slow);
        }
    }

    return NULL; // No cycle
}

int main() {
    // Create sample nodes
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* second = malloc(sizeof(struct ListNode));
    struct ListNode* third = malloc(sizeof(struct ListNode));
    struct ListNode* fourth = malloc(sizeof(struct ListNode));

    head->data = 1;   head->next = second;
    second->data = 2; second->next = third;
    third->data = 3;  third->next = fourth;
    fourth->data = 4; fourth->next = NULL;  // No loop initially

    // Detect cycle (none expected)
    struct ListNode* loopNode = detectCycle(head);
    if (loopNode == NULL)
        printf("No loop detected.\n");
    else
        printf("Loop starts at node with data: %d\n", loopNode->data);

    // Create a loop: link the last node back to second node
    fourth->next = second;

    // Detect cycle again
    loopNode = detectCycle(head);
    if (loopNode == NULL)
        printf("No loop detected.\n");
    else
        printf("Loop starts at node with data: %d\n", loopNode->data);

    // Normally you would free memory, but since we created a loop,
    // freeing would cause an infinite loop — so we skip it here.
    return 0;
}
