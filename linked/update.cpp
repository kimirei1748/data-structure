//BSE-01-0153/2025 KIMIREI MUSA
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Update node at a given index
void updateValue(Node* head, int index, int newValue) {
    int i = 0;
    Node* current = head;
    while (current) {
        if (i == index) {
            cout << "Updating index " << index << " from " << current->data << " to " << newValue << endl;
            current->data = newValue;
            return;
        }
        current = current->next;
        i++;
    }
    cout << "Index " << index << " out of range." << endl;
}

// Display list
void traverse(Node* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    traverse(head);

    updateValue(head, 1, 99);  // Change value at index 1 (20 → 99)

    traverse(head);

    updateValue(head, 5, 88);  // Invalid index
    return 0;
}
