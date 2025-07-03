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

// Search for a value and return its index
void searchValue(Node* head, int key) {
    int index = 0;
    Node* current = head;
    while (current) {
        if (current->data == key) {
            cout << "Value " << key << " found at index " << index << endl;
            return;
        }
        current = current->next;
        index++;
    }
    cout << "Value " << key << " not found in the list." << endl;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    searchValue(head, 30);  // Found
    searchValue(head, 50);  // Not found

    return 0;
}
