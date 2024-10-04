#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode; // Pointer to the top of the stack

public:
    Stack() {
        topNode = nullptr; // Initialize the stack as empty
    }
    
    // Push an element to the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode; // Link the new node to the previous top
        topNode = newNode; // Update the top pointer
    }
    
    // Remove and return the top element of the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next; // Move the top to the next node
        delete temp; // Free the memory of the removed node
    }
    
    // Return the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return topNode->data;
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }
    
    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << "Top element: " << s.top() << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
