//BSE-01-0153/2025 KIMIREI MUSA

#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1) front = 0; // First insert

        arr[++rear] = value;
        cout << value << " enqueued." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[front] << " dequeued." << endl;

        if (front == rear) {
            // Reset after last element is removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Peek front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    // Display all queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.peek();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Underflow check

    return 0;
}
