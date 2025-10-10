#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to detect a loop in a linked list
bool hasCycle(struct ListNode* head) {
    struct ListNode* slowPtr = head;
    struct ListNode* fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            return true; // Loop detected
        }
    }

    return false; // No loop
}

// Example usage
int main() {
    // Create nodes
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* second = malloc(sizeof(struct ListNode));
    struct ListNode* third = malloc(sizeof(struct ListNode));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; // No cycle

    // Test
    if (hasCycle(head))
        printf("Loop detected.\n");
    else
        printf("No loop detected.\n");

    // Optional: Create a cycle for testing
    third->next = head; // Introduce loop

    if (hasCycle(head))
        printf("Loop detected after linking back.\n");
    else
        printf("No loop detected after linking back.\n");

    return 0;
}
