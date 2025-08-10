// pair is used to store two values which can also be of different datatype
// it is basically used to store tuples

#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,char> p; //a pair is created

    p.first = 1;
    p.second = 'a';

    cout<<"p -> "<<p.first<<" "<<p.second<<endl; // pair's first value and second value 

    pair<int,int> p10;
    p10.first = 10;
    p10.second = 20;
    cout<<endl<<"Before swapping : "<<endl;
    cout<<"p10 -> "<<p10.first<<" "<<p10.second<<endl;

    pair<int,int> p20;
    p20.first = 100;
    p20.second = 200;
    cout<<"p20 -> "<<p20.first<<" "<<p20.second<<endl;

    p10.swap(p20); //to swap two pairs
    // note : swapping can be done only if the datatypes of 2 elements is same
    cout<<endl<<"After swapping : "<<endl; 
    cout<<"p10 -> "<<p10.first<<" "<<p10.second<<endl;
    cout<<"p20 -> "<<p20.first<<" "<<p20.second<<endl<<endl;

    pair<int,char> p2(2,'b');
    pair<int,int> p3(p10); //copying already existing pair to the new pair

    cout<<"p3 -> "<<p3.first<<" "<<p3.second<<endl;

    

}