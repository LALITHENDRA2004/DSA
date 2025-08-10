#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v1; //zero length vector
    vector<char> v2(5); //5 element character vector
    vector<char> v3(v2); //5 element character vector from v2
    vector<int> v4(6,3); //6 element vector of 3's
    display(v4);
    int size,ele;
    cout<<"Enter the size : ";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter an element to add into v1: \n";
        cin>>ele;
        v1.push_back(ele);
    }
    //v1.pop_back();
    display(v1);
    vector<int> :: iterator it1  = v1.begin();
    v1.insert(it1+1,5,100);
    display(v1);

}