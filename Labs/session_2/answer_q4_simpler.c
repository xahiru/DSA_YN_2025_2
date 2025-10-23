#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // --- Node 1 ---
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 5;
    newNode->next = NULL;
    head = newNode;
    temp = head;

    // --- Node 2 ---
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 6;
    newNode->next = NULL;
    temp->next = newNode;
    temp = temp->next;

    // --- Node 3 ---
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 7;
    newNode->next = NULL;
    temp->next = newNode;

    // Display the list
    printf(" Data entered in the list :\n");
    temp = head;
    while (temp != NULL) {
        printf(" Data = %d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
