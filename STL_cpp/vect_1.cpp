#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v1; //dynamic array

    v1.push_back(10);
    cout<<v1[0]<<endl;//  ----> 1
    cout<<v1.at(0)<<endl;//---> 2        both 1 and 2 can be used but 2 is efficient

    v1[0] = 20;    //can be used for updating values
    cout<<v1[0]<<endl;  //v1[0] after updating the value

    //cout<<v1[1]<<endl;          //prints garabage value since index does not exist 
    //cout<<v1.at(1)<<endl;       //throws an error

    v1.pop_back();  //last element is removed
    //cout<<v1.at(0);
    //cout<<v1.size();


    for(int i=0;i<10;i++) //using loop for inserting elements 
    {
        v1.push_back(i+1); //push_back increases the size for every time it is used
        cout<<v1[i]<<" ";
    }

    v1.assign(10,20); //assigns 10 extra elements with value 20
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<" ";
    }

    v1.insert(v1.begin(),10); //inserts 10 at the beginning 
    v1.insert(v1.end(),100); //inserts 100 at the ending
    cout<<endl<<"After inserting 10 at the beginning: "<<v1.front();
    cout<<endl<<"After inserting 100 at the ending: "<<v1.back()<<endl;
  
    cout<<endl<<"Size: "<<v1.size()<<endl;

    cout<<"Front: "<<v1.front()<<endl; //returns the first element
    cout<<"Back: "<<v1.back()<<endl; //returns the last element

    cout<<"isEmpty v1: "<<v1.empty()<<endl; //returns 0 if it is not empty

    vector<int>v2;
    cout<<"isEmpty v2: "<<v2.empty()<<endl; //returns 1 if it is empty

    //prefer push_back function for inserting the elements into a vector

    // to reverse the vector
    reverse(v1.begin(), v1.end());

    for(auto i : v1){
        cout<<i<<" ";
    }
    cout<<endl;
    
    // to sort the vector
    sort(v1.begin(),v1.end());
    for(auto i : v1){
        cout<<i<<" ";
    }
}