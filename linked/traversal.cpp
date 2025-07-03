//BSE-01-0153/2025 KIMIREI MUSA
#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Function to print the linked list
void traverseList(Node* head) {
    Node* current = head;
    cout << "Linked List Traversal:" << endl;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Assign data and links
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    // Traverse the list
    traverseList(head);

    return 0;
}
