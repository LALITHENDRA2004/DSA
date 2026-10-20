#include<bits/stdc++.h>
using namespace std;

class Node {
    private:
        int data;
        Node *next;

    public:
        Node() {
            data = 0;
            next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

        void setData(int data) {
            this->data = data;
        }

        int getData() {
            return data;
        }

        void setNext(Node *next) {
            this->next = next;
        }

        Node* getNext() {
            return next;
        }
};

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList() {
            head = NULL;
        }

        ~LinkedList() {
            Node* temp = head;
            while (temp != nullptr) {
                Node* next = temp->getNext();
                delete temp;
                temp = next;
            }
        }


        void setHead(Node *head) {
            this->head = head;
        }

        Node* getHead() {
            return head;
        }

        Node* createNode(int data) {
            Node* node = new Node(data);
            return node;
        }

        void insertAtHead(int data) {
            Node* node = createNode(data);
            if(head != NULL) {
                node->setNext(head);
            }
            head = node;
        }

        void insertAtTail(int data) {
            Node *node = createNode(data);
            if(head == NULL) {
                head = node;
                return;
            }
            Node *temp = head;
            while(temp->getNext() != NULL) {
                temp = temp->getNext();
            }
            temp->setNext(node);
        }

        void deleteAtHead() {
            if(head == NULL) {
                cout << "List is empty.";
                return;
            }
            Node* delNode = head;
            head = head->getNext();
            delete delNode;
        }

        void deleteAtTail() {
            if(head == NULL) {
                cout << "List is empty.";
                return;
            }
            else if(head -> getNext() == NULL) {
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while(temp->getNext()->getNext() != NULL) {
                temp = temp->getNext();
            }
            Node* delNode= temp->getNext();
            temp->setNext(NULL);
            delete delNode;
        }

        void display() {
            if(head == NULL) {
                cout << "List is empty.";
                return;
            }
            Node *temp = head;
            while(temp) {
                cout << temp -> getData() << " ";
                temp = temp -> getNext();
            }
        }
};

int main() {
    
    LinkedList list;
    int choice, data;
    
    while(true) {
        cout << "1. Insert at Head\n2. Insert at Tail\n3. Delete at Head\n4. Delete at Tail\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the node data: ";
                cin >> data;
                list.insertAtHead(data);
                break;
            case 2:
                cout << "Enter the node data: ";
                cin >> data;
                list.insertAtTail(data);
                break;
            case 3:
                list.deleteAtHead();
                break;
            case 4:
                list.deleteAtTail();
                break;
            case 5: 
                list.display();
                cout << "\n";
                break;
            case 6: 
                return 0;
            default:
                cout << "Please select a valid choice.";
        }
    }

    return 0;
}