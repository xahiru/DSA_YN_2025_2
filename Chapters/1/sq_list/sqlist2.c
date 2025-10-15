#include <stdio.h>

#define ListSize 100
typedef int DataType;

typedef struct {
    DataType data[ListSize];
    int length;
} Sqlist;

// Function to initialize the list (set length to 0)
void setnull(Sqlist *p) {
    p->length = 0;
}

// Function to get the length of the list
int length(Sqlist *p) {
    return p->length;
}

// Function to get an element at a given index
void get(Sqlist *p, int i) {
    if (i < 1 || i > p->length) {
        printf("Index out of bounds\n");
    } else {
        printf("Element at index %d is: %d\n", i, p->data[i - 1]);
    }
}

// Function to locate the first occurrence of an element x
void locate(Sqlist *p, DataType x) {
    int i = 0;
    while (i < p->length && p->data[i] != x) {
        i++;
    }
    if (i == p->length) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", i + 1);
    }
}

// Function to insert an element x at position i
void insert(Sqlist *p, int i, DataType x) {
    if (i < 1 || i > p->length + 1 || p->length >= ListSize) {
        printf("Invalid position, cannot insert\n");
    } else {
        for (int j = p->length; j >= i; j--) {
            p->data[j] = p->data[j - 1];
        }
        p->data[i - 1] = x;
        p->length++;
        printf("List after insertion: ");
        for (int j = 0; j < p->length; j++) {
            printf("%d -> ", p->data[j]);
        }
        printf("\n");
    }
}

// Function to delete an element at position i
void delete(Sqlist *p, int i) {
    if (i < 1 || i > p->length) {
        printf("Index out of bounds\n");
    } else {
        for (int j = i - 1; j < p->length - 1; j++) {
            p->data[j] = p->data[j + 1];
        }
        p->length--;
        printf("List after deletion: ");
        for (int j = 0; j < p->length; j++) {
            printf("%d -> ", p->data[j]);
        }
        printf("\n");
    }
}

// Function to display the list
void display(Sqlist *p) {
    if (p->length == 0) {
        printf("The list is empty\n");
    } else {
        printf("The list: ");
        for (int j = 0; j < p->length; j++) {
            printf("%d -> ", p->data[j]);
        }
        printf("\n");
    }
}

// Optional: Function to sort the list (ascending)
void sort(Sqlist *p) {
    for (int i = 0; i < p->length - 1; i++) {
        for (int j = i + 1; j < p->length; j++) {
            if (p->data[i] > p->data[j]) {
                DataType temp = p->data[i];
                p->data[i] = p->data[j];
                p->data[j] = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// Main function to test the list operations
int main() {
    Sqlist l;
    setnull(&l);
    int select, i;
    DataType x;

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
        printf("7: Sort the list\n");
        printf("8: Display the list\n");
        printf("0: Exit\n");
        printf("Choose an option (0-8): ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                setnull(&l);
                printf("List cleared.\n");
                break;
            case 2:
                printf("Length of the list: %d\n", length(&l));
                break;
            case 3:
                printf("Enter index to retrieve: ");
                scanf("%d", &i);
                get(&l, i);
                break;
            case 4:
                printf("Enter element to locate: ");
                scanf("%d", &x);
                locate(&l, x);
                break;
            case 5:
                printf("Enter position and element to insert (position element): ");
                scanf("%d %d", &i, &x);
                insert(&l, i, x);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                delete(&l, i);
                break;
            case 7:
                sort(&l);
                display(&l);
                break;
            case 8:
                display(&l);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please choose between 0-8.\n");
        }
    } while (select != 0);

    return 0;
}
