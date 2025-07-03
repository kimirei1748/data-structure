//BSE-01-0153/2025 KIMIREI MUSA

#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    // Peek operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // Check if empty
    bool isEmpty() {
        return top == -1;
    }

    // Display all stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.display();

    s.pop();
    s.peek();
    s.display();

    return 0;
}
