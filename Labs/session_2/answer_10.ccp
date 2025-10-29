#include <iostream>
#include <string>

using namespace std;

// Student structure
struct Student {
    int id;
    string name;
    int age;
};

// Node structure
struct Node {
    Student data;
    Node* next;
};

// Function to add a new node at the end
void addNode(Node*& head, int id, const string& name, int age) {
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.name = name;
    newNode->data.age = age;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to count nodes
int countNodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to display the list
void displayList(Node* head) {
    while (head != nullptr) {
        cout << "ID: " << head->data.id
             << ", Name: " << head->data.name
             << ", Age: " << head->data.age << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;

    // Adding sample students
    addNode(head, 20240001, "Micheal", 22);
    addNode(head, 20240003, "Ismeal", 18);
    addNode(head, 20240002, "Olaaf", 23);
    addNode(head, 20240004, "Rishmy", 20);

    cout << "Student List:" << endl;
    displayList(head);

    cout << "Number of students = " << countNodes(head) << endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
