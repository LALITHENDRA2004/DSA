#include<bits/stdc++.h> 
using namespace std; 

class Stack {
    private:
        int capacity; 
        int *arr;
        int top;

    public: 
        Stack(int cap) {
            capacity = cap;
            arr = new int[capacity];
            top = -1;
        }

        void push(int ele) {
            if(top == capacity - 1) {
                cout << "Stack is full.";
                return;
            }

            arr[++top] = ele;
        }

        int pop() {
            if(top == -1) {
                cout << "Stack is empty.";
                return -1;
            }

            return arr[top--];
        }

        int peek() {
            if(top == -1) {
                cout << "Stack is empty.";
                return -1;
            }

            return arr[top];
        }

        bool isEmpty() {
            return top == -1;
        }
};

int main() {
    Stack stack(3);

    stack.push(10);
    cout << stack.peek() << endl;
    stack.push(20);
    cout << stack.peek() << endl;
    stack.push(30);
    cout << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    cout << stack.isEmpty() << endl;
}