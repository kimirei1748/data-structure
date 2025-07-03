//BSE-01-0153/2025 KIMIREI MUSA
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert at a given position (0-based index)
void insertAtPosition(Node*& head, int position, int value) {
    if (position == 0) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds!" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Traverse and print the list
void traverseList(Node* head) {
    Node* current = head;
    cout << "Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 30);  // List: 30
    insertAtBeginning(head, 20);  // List: 20 → 30
    insertAtEnd(head, 50);        // List: 20 → 30 → 50
    insertAtPosition(head, 2, 40); // List: 20 → 30 → 40 → 50

    traverseList(head);

    return 0;
}
