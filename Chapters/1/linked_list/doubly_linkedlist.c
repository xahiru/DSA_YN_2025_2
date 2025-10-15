#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct dlistnode {
    datatype data;
    struct dlistnode *prev, *next;
} dlistnode;

typedef dlistnode *dlinklist;

// Function to create a new node
dlistnode* createNode(datatype data) {
    dlistnode* newNode = (dlistnode*)malloc(sizeof(dlistnode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the end of the list
void insert(dlinklist *head, datatype data) {
    dlistnode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    dlistnode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete the first occurrence of an element
void deleteNode(dlinklist *head, datatype data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    dlistnode* temp = *head;

    // Find the node to delete
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    // If the node to be deleted is the head
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to traverse and print elements forward
void traverseForward(dlinklist head) {
    dlistnode* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to traverse and print elements backward
void traverseBackward(dlinklist head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    dlistnode* temp = head;
    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    dlinklist head = NULL;

    // Insert elements
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("After insertion:\n");
    traverseForward(head);
    traverseBackward(head);

    // Delete an element
    deleteNode(&head, 3);
    printf("\nAfter deleting 3:\n");
    traverseForward(head);
    traverseBackward(head);

    return 0;
}
