#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student structure
struct Student {
    int id;
    char name[50];
    int age;
};

// Node structure
struct Node {
    struct Student data;
    struct Node* next;
};

// Function to add a new node at the end
void addNode(struct Node** head, int id, const char* name, int age) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data.id = id;
    strcpy(newNode->data.name, name); // Using strcpy
    newNode->data.age = age;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to display the list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n",
               head->data.id, head->data.name, head->data.age);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Adding sample students
    addNode(&head, 20240001, "Micheal", 22);
    addNode(&head, 20240003, "Ismeal", 18);
    addNode(&head, 20240002, "Olaaf", 23);
    addNode(&head, 20240004, "Rishmy", 20);

    printf("Student List:\n");
    displayList(head);

    printf("Number of students = %d\n", countNodes(head));

    return 0;
}
