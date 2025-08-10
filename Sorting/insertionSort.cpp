#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
    for(int i = 1 ; i < arr.size() ; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

int main() 
{
    vector<int> arr;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    insertionSort(arr);

    for(int i : arr) {
        cout << i << " ";
    }
}