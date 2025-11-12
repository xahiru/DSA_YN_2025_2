#include <iostream>
using namespace std;

#define MAX_SIZE 1000 // Maximum size of stack

class Stack {
private:
    int top; // Index of top element
    int arr[MAX_SIZE]; // Array to store elements

public:
    Stack() {
        top = -1; // Initialize top index to -1 (empty stack)
    }

    bool push(int x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full" << endl; // Display message if stack is full
            return false; // Return false to indicate failure in pushing element
        }
        arr[++top] = x; // Increment top index and add element to array
        return true; // Return true to indicate successful element addition
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in popping element
        }
        return arr[top--]; // Return top element and decrement top index
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in peeking element
        }
        return arr[top]; // Return top element without modifying top index
    }

    bool isEmpty() {
        return (top < 0); // Return true if stack is empty (top index is -1)
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return;
        }
        cout << "\nStack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " "; // Display elements of the stack
        cout << endl;
    }
};

int main() {
    //Initialize a stack 
    cout << "Create a stack object:\n";
    Stack s; 
    cout << "Check the stack is empty or not? ";
    cout << s.isEmpty() << endl; // Check if the stack is empty
    cout << "\nInsert some elements onto the stack:\n";
    s.push(7); 
    s.push(6);
    s.push(5);
    s.push(4);
    s.display(); // Display elements in the stack
    cout << "\nRemove an element from the stack! ";
    cout << s.pop(); // Pop an element from the stack
    s.display(); // Display elements in the stack
    cout << "\nTop of the element of the stack:\n";
    cout << s.peek(); // Display the top element of the stack
    cout << endl;
    return 0;
}
