#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int d){
        data = d;
        next = NULL;
    }
};

Node *head = NULL;

void InsertAtFront(int data){
    Node *mynode = new Node(data);
    if(head == NULL) head = mynode;
    else{
        mynode->next = head;
        head = mynode;
    } 
}

void InsertAtEnd(int data){
    Node *mynode = new Node(data);
    if(head == NULL) head = mynode;
    else{
        Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = mynode;
    }
}

void InsertAtPos(int pos,int data){ // 1 2 4 5 6 
    Node *mynode = new Node(data);
    if(pos == 1) InsertAtFront(data);
    else{
        Node *temp = head;
        for(int i = 1 ; i < pos - 1 ; i++) {  //ex 5 pos   ----- 4 ----i 
            temp = temp -> next;
        }
        mynode -> next = temp -> next;
        temp -> next = mynode;
    }
}
void DeleteAtFront(){
    if(head == NULL){
        cout<<"There are no nodes to delete";
        return;
    }
    else{
        Node *dn = head;
        head = head->next;
        delete dn;
    }
}

void DeleteAtEnd(){
    if(head == NULL){
        cout<<"There ar no nodes to delete";
        return;
    }
    else{
        Node *temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        Node *dn = temp->next;
        temp->next = NULL;
        delete dn;
    }
}

void DeleteAtPos(int pos){
    if(head == NULL){
        cout<<"There are no nodes to delete";
        return;
    }
    else if(pos == 1) DeleteAtFront();
    else{
        Node *temp = head;
        while(pos-2 != 0){
            pos--;
            temp = temp->next;
        }
        Node *dn = temp->next;
        temp->next = dn->next;
        delete dn;
    }
}

void display(){
    if(head == NULL) cout<<"\nThere are no nodes to display\n";
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool SearchElement(int element){
    Node *temp = head;
    while(temp){
        if(temp->data == element) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LengthOfLinklist(){
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    cout << "Length of Linked list is " << count << endl;
}

void Reverse(){
    Node *prevnode = NULL, *currnode = head, *nextnode = head;
    while(currnode != NULL){
        nextnode = nextnode -> next;
        currnode -> next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
    display();
}

int MiddleOfLL(){
    Node *slow = head, *fast = head;
    while(fast != NULL and fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow -> data;
}

bool DetectCycle(){
    Node *slow = head, *fast = head;
    while(fast and fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    while(1){
        cout<<"Choose\n1.Insert at front\n2.Insert at end\n3.Insert at position\n4.Delete at front\n5.Delete at end\n6.Delete at position\n7.Display\n8.Search element\n9.Length of linked list\n10.Reverse\n11.Middle of Linked list\n12.Detect cycle\nAny other to break\n";
        int choice;
        cin >> choice;
        if(choice == 1){
            int data;
            cout<<"Enter data to be inserted : ";
            cin >> data;
            InsertAtFront(data);
        }
        else if(choice == 2){
            int data;
            cout<<"Enter data to be inserted : ";
            cin >> data;
            InsertAtEnd(data);
        }
        else if(choice == 3){
            int pos,data;
            cout<<"Enter position and data to be inserted : ";
            cin >> pos >> data;
            InsertAtPos(pos,data);
        }
        else if(choice == 4){
            DeleteAtFront();
        }
        else if(choice == 5){
            DeleteAtEnd();
        }
        else if(choice == 6){
            int pos;
            cout<<"Enter the position to be deleted : ";
            cin >> pos;
            DeleteAtPos(pos);
        }
        else if(choice == 7){
            display();
        }
        else if(choice == 8){
            int element;
            cout << "Enter an element : ";
            cin >> element;
            int x = SearchElement(element);
            if(x == true) cout << "Element Found";
            else cout << "Element Not Found";
        }
        else if(choice == 9){
            LengthOfLinklist();
        }
        else if(choice == 10){
            Reverse();
        }
        else if(choice == 11) {
            int mid = MiddleOfLL();
            cout << "Middle element of the linked list is " << mid << endl;  
        }
        else if(choice == 12){
            if(DetectCycle() == true) {
                cout << "The linked list forms a cycle \n";
            }
            else {
                cout << "The linked list does not form a cycle \n";
            }
        }
        else break;
    }
    return 0;
}


