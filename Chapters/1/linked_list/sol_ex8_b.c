#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

void deleteFirst(struct DNode** head) {
    if (*head == NULL)
        return;

    struct DNode* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

// Example usage
int main() {
    struct DNode* head = malloc(sizeof(struct DNode));
    head->data = 10;
    head->prev = NULL;
    head->next = malloc(sizeof(struct DNode));
    head->next->data = 20;
    head->next->prev = head;
    head->next->next = NULL;

    deleteFirst(&head);

    if (head)
        printf("New head data = %d\n", head->data);
    else
        printf("List is now empty\n");

    return 0;
}
