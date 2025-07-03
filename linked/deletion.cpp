//BSE-01-0153/2025 KIMIREI MUSA
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end (used to build the list)
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

// Delete from beginning
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

// Delete at a specific position
void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (pos == 0) {
        deleteFromBeginning(head);
        return;
    }

    Node* current = head;
    for (int i = 0; i < pos - 1 && current->next != nullptr; i++) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Traverse the list
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

    // Build list: 10 → 20 → 30 → 40
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    traverseList(head);

    deleteFromBeginning(head);  // Removes 10
    traverseList(head);

    deleteFromEnd(head);        // Removes 40
    traverseList(head);

    deleteAtPosition(head, 1);  // Removes 30 (index 1 after above deletions)
    traverseList(head);

    return 0;
}
