#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node *head = NULL;

void insertAtHead(int data) {
    Node *newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
}

void display() {
    if(head == NULL) cout << "No nodes to display.\n";
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

}

int main() {

    insertAtHead(10);
    insertAtHead(9);
    insertAtHead(8);
    insertAtHead(7);

    display();


    return 0;
}