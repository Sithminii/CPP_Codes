// Implementation of a stack using an array

#include <iostream>
#include <chrono>

using namespace std;

const int maxSize = 20;

class stack { //define a new class type stack
private:
    int top; //index of the topmost element of the stack
    int array[maxSize]; //fix the size of the stack
public:
    stack() {
        top = -1; //initializing value of top to indicate empty stack
    }

    bool isFull() { //function to check whether stack is full
        return top == maxSize - 1;
    }

    bool isEmpty() { //function to check whether stack is empty
        return top == -1;
    }

    void push(int value) { //function to insert elements to the stack
        if (isFull()) {
            cout << "Error: Stack Overflow!" << endl; //Display error when stac is already full
            return;
        }
        //increament top index and insert the element to the top of the stack
        top++; 
        array[top] = value;
    }

    int pop() { //function to access stack elements
        if (isEmpty()) {
            cout << "Error: Stack Underflow!" << endl;//Display error when pop from empty list
            return -1;
        }
        int temp = array[top];
        top--; // set the new top index
        return temp;
    }

    void display() { // function to display all the elements of the stack
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for (int j = top; j >= 0; j--) {
            cout << array[j] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack S;

    auto start = chrono::steady_clock::now();

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

    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.display();

    S.push(4);
    S.push(30);
    S.push(3);
    S.push(1);
    S.display();

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Execution time is " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    return 0;
}
