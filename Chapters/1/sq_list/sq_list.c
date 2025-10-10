#include <stdio.h>

#define MAXSIZE 50 // Maximum size of the list

// Structure definition for sqlist
struct sqlist {
    int elemlist[MAXSIZE]; // Array to store list elements
    int size;              // Current size of the list
};

// Function to initialize the list
void setnull(struct sqlist *p) {
    p->size = 0;
    printf("List cleared.\n");
}

// Function to get the length of the list
int length(struct sqlist l) {
    return l.size;
}

// Function to get an element at a given index
void get(struct sqlist l, int i) {
    if (i < 1 || i > l.size)
        printf("Index out of bounds.\n");
    else
        printf("Element at index %d is: %d\n", i, l.elemlist[i - 1]);
}

// Function to locate the first occurrence of an element x
void locate(struct sqlist l, int x) {
    for (int i = 0; i < l.size; i++) {
        if (l.elemlist[i] == x) {
            printf("Element found at index: %d\n", i + 1);
            return;
        }
    }
    printf("Element not found.\n");
}

// Function to insert an element x at position i
void insert(struct sqlist *p, int i, int x) {
    if (i < 1 || i > p->size + 1 || p->size >= MAXSIZE) {
        printf("Invalid position, cannot insert.\n");
        return;
    }

    for (int j = p->size; j >= i; j--)
        p->elemlist[j] = p->elemlist[j - 1];

    p->elemlist[i - 1] = x;
    p->size++;

    printf("List after insertion: ");
    for (int j = 0; j < p->size; j++)
        printf("%d -> ", p->elemlist[j]);
    printf("\n");
}

// Function to delete an element at position i
void deleteElem(struct sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        printf("Index out of bounds.\n");
        return;
    }

    for (int j = i - 1; j < p->size - 1; j++)
        p->elemlist[j] = p->elemlist[j + 1];

    p->size--;

    printf("List after deletion: ");
    for (int j = 0; j < p->size; j++)
        printf("%d -> ", p->elemlist[j]);
    printf("\n");
}





// Function to display the list
void display(struct sqlist l) {
    if (l.size == 0)
        printf("The list is empty.\n");
    else {
        printf("The list: ");
        for (int j = 0; j < l.size; j++)
            printf("%d -> ", l.elemlist[j]);
        printf("\n");
    }
}

// Main function to test all operations
int main() {
    struct sqlist l; // Define a list
    setnull(&l);     // Initialize it
    int choice, i, x;

    printf("Enter 4 initial elements:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &x);
        insert(&l, i + 1, x);
    }

    do {
        printf("\nMenu:\n");
        printf("1: Clear the list\n");
        printf("2: Display the length\n");
        printf("3: Get an element by index\n");
        printf("4: Locate an element\n");
        printf("5: Insert an element\n");
        printf("6: Delete an element\n");
        printf("9: Display the list\n");
        printf("0: Exit\n");
        printf("Choose an option (0-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setnull(&l);
                break;
            case 2:
                printf("Length of the list: %d\n", length(l));
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &i);
                get(l, i);
                break;
            case 4:
                printf("Enter element to locate: ");
                scanf("%d", &x);
                locate(l, x);
                break;
            case 5:
                printf("Enter position and element: ");
                scanf("%d %d", &i, &x);
                insert(&l, i, x);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                deleteElem(&l, i);
                break;
            case 9:
                display(l);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
