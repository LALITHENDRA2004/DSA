///priority queue --> arranges elements based on the priority
//2 types --> 1.max heap (decreasing) 2.min heap (increasing)

#include<bits/stdc++.h>
using namespace std;

void display_max_heap(priority_queue<int> &pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

void display_min_heap(priority_queue<int,vector<int>,greater<int>> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    priority_queue<int> pq1; //by default max heap

    pq1.push(10); //10
    pq1.push(30); //30,10 --> basing on priority of 30(max heap), it is pushed at front
    pq1.push(20); //30,20,10
    pq1.push(40); //40,30,20,10

    pq1.pop(); //30,20,10

    cout<<"Top : "<<pq1.top()<<endl;

    cout<<"Size : "<<pq1.size()<<endl;

    cout<<"Max heap is : ";
    display_max_heap(pq1);

    priority_queue<int,vector<int>,greater<int>> pq2; //min heap

    pq2.push(10); //10
    pq2.push(30); //10,30 --> based on the priority of 30(min heap) it is pushed at back
    pq2.push(20); //10,20,30
    pq2.push(40); //10,20,30,40

    pq2.pop(); // 20,30,40

    cout<<"Top : "<<pq2.top()<<endl;

    cout<<"Size : "<<pq2.size()<<endl;

    cout<<"Min heap is : ";
    display_min_heap(pq2);

    cout<<"pq is_empty : "<<pq2.empty(); //returns 0 since it is empty


}