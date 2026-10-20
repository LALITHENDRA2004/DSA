#include<bits/stdc++.h> 
using namespace std;

void print(int size, int arr[]) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int size, int arr[]) {
    for(int i = 1 ; i < size ; i++) {
        int ind = i;
        while(ind > 0 && arr[ind] < arr[ind-1]) {
            swap(arr[ind], arr[ind-1]);
            ind--;
        }
    }

    print(size, arr);
}

int main() {
    int size; 
    cin >> size;

    int arr[size];

    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    insertionSort(size, arr);
}