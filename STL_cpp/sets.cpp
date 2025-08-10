//set  --> 1. elements are in sorted order
//         2. no duplicates

//note : unordered set is almost same as set but it is not in a sorted order
//syntax : unordered_set<datatype> setname;

#include<bits/stdc++.h>
using namespace std;

void display(set<int> &s){
    for(auto x:s){ //using auto for printing the set
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    set<int> s; //creation of a set

    s.insert(50);
    s.insert(40);
    s.insert(30);
    s.insert(20);
    s.insert(10);

    display(s);

    auto x = s.find(10); //it finds the address of the element
    cout<<*x<<endl;
    
    cout<<s.count(20)<<endl; //if the element is is in the set ,it returns 1 else 0

    s.erase(40); //removes 40 element
    display(s);

    cout<<s.size();
}