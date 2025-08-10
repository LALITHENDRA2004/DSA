//deque  --> can push and pop elements from front and back

#include<bits/stdc++.h>
using namespace std;

void display_from_front(deque<int> &dq){
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

void display_from_back(deque<int> &dq){
    while(!dq.empty()){
        cout<<dq.back()<<" ";
        dq.pop_back();
    }
    cout<<endl;
}

int main(){
    deque<int> dq; //creation of deque

    dq.push_back(30); //30
    dq.push_back(40); //30,40
    dq.push_front(20); //20,30,40
    dq.push_front(10); //10,20,30,40

    //display_from_back(dq);
    //display_from_front(dq);

    // dq.pop_back(); //10,20,30
    // dq.pop_front(); //20,30
    // dq.pop_front(); //30
    // dq.pop_back(); // no elements in the queue
    
    cout<<"Size : "<<dq.size()<<endl; //returns size 

    //display_from_front(dq);

    cout<<dq.back()<<endl; //returns the back element 

    cout<<dq.front(); // returns the front element 


}