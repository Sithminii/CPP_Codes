//Implementation of a stack using linked lists

#include <iostream>
#include <chrono> // for timing
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
};

// Stack class using linked list
class stack {
private:
    Node* head; // pointer to head of the stack
public:
    stack() {
        head = nullptr;
    }
    // function to push element to the top of stack
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    // function to remove and return the top element of stack
    int pop() {
        if (head == nullptr) {
            cout << "Error: Stack underflow\n";
            return -1;
        }
        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }
    // function to check if stack is empty
    bool isEmpty() {
        return (head == nullptr);
    }
    // function to display all the elements in the stack
    void display() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    stack S;
    auto start = chrono::high_resolution_clock::now();
    S.push(8);
    S.push(10);
    S.push(5);
    S.push(11);
    S.push(15);
    S.push(23);
    S.push(6);
    S.push(18);
    S.push(20);
    S.push(17);
    S.display();
    for (int i = 0; i < 5; i++) {
        S.pop();
    }
    S.display();
    S.push(4);
    S.push(30);
    S.push(3);
    S.push(1);
    S.display();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}
