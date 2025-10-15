#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the end of the circular doubly linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // First node: points to itself in both directions
        *head = newNode;
        newNode->next = newNode->prev = newNode;
        return;
    }

    // Last node is one step before head
    struct Node* last = (*head)->prev;

    // Insert between last and head
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Function to delete the first occurrence of an element
void delete(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* curr = *head;

    // Find the node to delete
    while (curr->data != data) {
        curr = curr->next;
        if (curr == *head) {
            printf("Element not found\n");
            return;
        }
    }

    // Case 1: Only one node in the list
    if (curr->next == curr && curr->prev == curr) {
        free(curr);
        *head = NULL;
        return;
    }

    // Case 2: More than one node
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    // If deleting the head, move head forward
    if (curr == *head)
        *head = curr->next;

    free(curr);
}

// Function to traverse forward
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List (forward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to traverse backward
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* last = head->prev;
    struct Node* temp = last;

    printf("List (backward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("After insertion:\n");
    traverseForward(head);
    traverseBackward(head);

    // Delete a middle element
    delete(&head, 3);
    printf("\nAfter deleting 3:\n");
    traverseForward(head);
    traverseBackward(head);

    // Delete the head
    delete(&head, 1);
    printf("\nAfter deleting head (1):\n");
    traverseForward(head);
    traverseBackward(head);

    // Delete remaining
    delete(&head, 2);
    delete(&head, 4);
    printf("\nAfter deleting all elements:\n");
    traverseForward(head);
    traverseBackward(head);

    return 0;
}
