//lists --> it means linked list.operations can be performed on both the ends
//use of list than deque is : list contains sort and reverse predefined functions

#include<bits/stdc++.h>
using namespace std;

void display_front(list<int> &l){
    list<int> :: iterator i; //we should use iterator to loop over the elements
    for(i=l.begin();i!=l.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> l; //list is created
    l.push_back(10);  //10
    l.push_back(20);  //10,20
    l.push_front(30); //30,10,20
    l.push_front(40); //40,30,10,20

    display_front(l);

    cout<<"Front: "<<l.front()<<endl; //returns element at front
    cout<<"Back: "<<l.back()<<endl; //returns element at back

    l.pop_front(); //deletes element at front
    l.pop_back();  //deletes element at back

    display_front(l); //after deleting front and back elements

    l.push_back(50);
    l.push_back(20);
    
    l.sort(); //sorts the list

    display_front(l);

    l.reverse(); //reverses the list

    display_front(l);
}