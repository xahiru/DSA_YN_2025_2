#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

void display(struct CNode* head) {
    if (head == NULL)
        return;

    struct CNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Example usage
int main() {
    struct CNode* head = malloc(sizeof(struct CNode));
    struct CNode* second = malloc(sizeof(struct CNode));
    struct CNode* third = malloc(sizeof(struct CNode));

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = head; // circular link

    display(head);
    return 0;
}
