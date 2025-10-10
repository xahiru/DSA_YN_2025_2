#include <stdio.h>

#define MAXSIZE 50

// Global variables for simplicity
int list[MAXSIZE];
int size = 0;

// Function to clear the list
void setnull() {
    size = 0;
    printf("List cleared.\n");
}

// Function to get the length of the list
int length() {
    return size;
}

// Function to get an element at a given index
void get(int i) {
    if (i < 1 || i > size)
        printf("Index out of bounds.\n");
    else
        printf("Element at index %d is: %d\n", i, list[i - 1]);
}

// Function to locate the first occurrence of an element x
void locate(int x) {
    for (int i = 0; i < size; i++) {
        if (list[i] == x) {
            printf("Element found at index: %d\n", i + 1);
            return;
        }
    }
    printf("Element not found.\n");
}

// Function to insert an element x at position i
void insert(int i, int x) {
    if (i < 1 || i > size + 1 || size >= MAXSIZE) {
        printf("Invalid position, cannot insert.\n");
        return;
    }

    for (int j = size; j >= i; j--)
        list[j] = list[j - 1];

    list[i - 1] = x;
    size++;

    printf("List after insertion: ");
    for (int j = 0; j < size; j++)
        printf("%d -> ", list[j]);
    printf("\n");
}

// Function to delete an element at position i
void deleteElem(int i) {
    if (i < 1 || i > size) {
        printf("Index out of bounds.\n");
        return;
    }

    for (int j = i - 1; j < size - 1; j++)
        list[j] = list[j + 1];

    size--;

    printf("List after deletion: ");
    for (int j = 0; j < size; j++)
        printf("%d -> ", list[j]);
    printf("\n");
}

// Function to perform insertion sort
void insertsort() {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }

    printf("Sorted list (Insertion Sort): ");
    for (int i = 0; i < size; i++)
        printf("%d -> ", list[i]);
    printf("\n");
}

// Function to perform bubble sort
void bubblesort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("Sorted list (Bubble Sort): ");
    for (int i = 0; i < size; i++)
        printf("%d -> ", list[i]);
    printf("\n");
}

// Function to display the list
void display() {
    if (size == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("The list: ");
    for (int i = 0; i < size; i++)
        printf("%d -> ", list[i]);
    printf("\n");
}

// Main program
int main() {
    int choice, i, x;

    printf("Enter 4 initial elements:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &x);
        insert(i + 1, x);
    }

    do {
        printf("\nMenu:\n");
        printf("1: Clear the list\n");
        printf("2: Display the length\n");
        printf("3: Get an element by index\n");
        printf("4: Locate an element\n");
        printf("5: Insert an element\n");
        printf("6: Delete an element\n");
        printf("7: Insertion sort\n");
        printf("8: Bubble sort\n");
        printf("9: Display the list\n");
        printf("0: Exit\n");
        printf("Choose an option (0-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setnull();
                break;
            case 2:
                printf("Length of the list: %d\n", length());
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &i);
                get(i);
                break;
            case 4:
                printf("Enter element to locate: ");
                scanf("%d", &x);
                locate(x);
                break;
            case 5:
                printf("Enter position and element: ");
                scanf("%d %d", &i, &x);
                insert(i, x);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                deleteElem(i);
                break;
            case 7:
                insertsort();
                break;
            case 8:
                bubblesort();
                break;
            case 9:
                display();
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
