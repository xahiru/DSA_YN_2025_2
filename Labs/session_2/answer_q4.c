#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL, *temp = NULL;
    int n, data;

    printf("Input the number of nodes : ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Input data for node %d : ", i);
        scanf("%d", &data);

        if(head == NULL) {         
            head = createNode(data);
            temp = head;
        } else {                
            temp->next = createNode(data);
            temp = temp->next;
        }
    }

    printf("\nData entered in the list:\n");
    printList(head);

    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
