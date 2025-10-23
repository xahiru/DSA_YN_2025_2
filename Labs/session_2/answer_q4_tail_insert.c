#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the list
void insert(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(struct Node *head) {
    printf(" Data entered in the list :\n");
    struct Node *temp = head;
    while (temp != NULL) {
        printf(" Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;

    // Hardcoded values
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);

    // Display the list
    display(head);

    return 0;
}
