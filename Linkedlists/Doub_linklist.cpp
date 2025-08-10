#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *next;
    Node *prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node *head = NULL;

void insertAtHead(int data) {
    Node *mynode = new Node(data);
    if(head == NULL) {
        head = mynode;
    }
    else {
        mynode -> next = head;
        head -> prev = mynode;
        head = mynode;
    }
}

void insertAtTail(int data) {
    Node *mynode = new Node(data);
    if(head == NULL) {
        head = mynode;
    }
    else {
        Node *temp = head;
        while(temp -> next ) {
            temp = temp -> next;
        }
        mynode -> prev = temp;
        temp -> next = mynode;
    }
}

void insertAtPos(int pos,int data) {
    Node *mynode = new Node(data);
    if(head == NULL) head = mynode;
    else if(pos == 1) {
        insertAtHead(data);
    }
    else {
        Node *temp = head;
        for(int i = 1 ; i < pos - 1 ; i++) {
            temp = temp -> next;
        }
        temp -> next -> prev = mynode; // 1 2 4 5 6 
        mynode -> next = temp -> next;
        mynode -> prev = temp;
        temp -> next = mynode;

    }
}

void deleteAtHead() {
    if(head == NULL) cout << "No nodes to delete" << endl;
    else {
        Node *dn = head;
        head = head -> next;
        if(head != NULL) head -> prev = NULL;
        delete dn;
    }
}

void deleteAtTail() {
    if(head == NULL) cout << "There are no nodes to delete";
    else {
        Node *temp = head;
        while(temp -> next -> next) {
            temp = temp -> next;
        }
        Node *dn = temp -> next;
        temp -> next = NULL;
        delete dn;

    }
}

void deleteAtPos(int pos) {
    if(head == NULL) cout << "There are no nodes to display";
    else if(pos == 1) deleteAtHead();
    else {
        Node *temp = head;
        for(int i = 1 ; i < pos - 1 ; i++) { // 1 2 3 4 5 
            temp = temp -> next;
        }
        Node *dn = temp -> next;
        temp -> next = dn -> next;
        dn -> next -> prev = temp;
     }
}

void display() {
    if(head == NULL) cout << "There are no nodes to display";
    Node *temp = head;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

}

int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtTail(40);
    insertAtTail(70);
    insertAtTail(60);
    insertAtTail(50);
    insertAtPos(1,100);
    deleteAtHead();
    deleteAtTail();
    deleteAtPos(3);
    display();
    return 0;
}