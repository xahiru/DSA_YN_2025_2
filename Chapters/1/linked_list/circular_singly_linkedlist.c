#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert an element at the end of the circular list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // First node — points to itself
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        // Traverse to the last node (that points back to head)
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Maintain circular link
    }
}

// Function to delete the first occurrence of an element
void delete(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *curr = *head, *prev = NULL;

    // Case 1: Deleting the head node
    if (curr->data == data) {
        // Only one node case
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
            return;
        }

        // Find the last node to maintain circular structure
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        last->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Case 2: Deleting a non-head node
    prev = curr;
    curr = curr->next;
    while (curr != *head && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == *head) {
        printf("Element not found\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Function to traverse and print the elements of the circular list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("List after insertion:\n");
    traverse(head);

    // Delete an element
    delete(&head, 3);
    printf("List after deleting 3:\n");
    traverse(head);

    // Delete head
    delete(&head, 1);
    printf("List after deleting head (1):\n");
    traverse(head);

    // Delete remaining
    delete(&head, 2);
    delete(&head, 4);
    printf("List after deleting all elements:\n");
    traverse(head);

    return 0;
}
