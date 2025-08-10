//map --> used to store key-value pairs in sorted order with respect to keys
//note : No two same keys are possible

//unordered_map is not in sorted order

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,char> m; //map is created int,char ->key,value

    m.insert({1,'a'}); //to insert a key value pair
    m[2] = 'b';        //another method to insert
    m[3] = 'c';
    m[4] = 'd'; 

    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl; //x.first -> key ,x.second -> value 
    }

    auto val = m.find(2); // to find the iterator position at key 2

    cout<<val->first<<" "<<val->second<<endl; //val is the iterator of 2 (-> is used)

    if(m.find(4)!=m.end()){ //m.end() indicates position after the last key (NULL)
        cout<<"Present"<<endl;
    }
    else cout<<"Absent"<<endl;

    if(m[4]) cout<<"Present"<<endl;
    else cout<<"Absent"<<endl;
}