//queue  --> pushes elements from back and pops elements from front

#include<bits/stdc++.h>
using namespace std;

void display(queue<int> &q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q; //creation of a queue

    q.push(10); //adds 10 to the queue
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<"Size : "<<q.size()<<endl; //returns size of queue

    q.pop(); //removes front element from the queue
    cout<<"Front element after popping : "<<q.front();
    cout<<endl;

    cout<<"Size of queue after popping : "<<q.size()<<endl;
    cout<<"q is_empty : "<<q.empty()<<endl; //returns 0 since it is not empty
    
    cout<<"The elements in the queue are : ";
    display(q);
    cout<<"q is_empty : "<<q.empty(); //returns 1 since it is empty

    
}