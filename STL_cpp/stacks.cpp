// stacks --> insertions and deletions are performed on same end (LIFO)

#include<bits/stdc++.h>
using namespace std;

void display(stack<int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    stack<int> s; //stack is created
    s.push(10);
    s.push(20); //elements are inserted
    s.push(30);
    s.push(40);

    cout<<"Top 1: "<<s.top()<<endl; //returns the element at top

    s.pop(); //deletes the element at top

    cout<<"Top 2: "<<s.top()<<endl;

    cout<<"Is_empty: "<<s.empty()<<endl; //returns 0 if s is not empty else 1

    cout<<"Size: "<<s.size()<<endl; //returns the size of stack

    display(s);

}


