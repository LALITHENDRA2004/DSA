#include<bits/stdc++.h> 
using namespace std;

void print(int size, int arr[]) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int size, int arr[]) {
    for(int i = 0 ; i < size - 1 ; i++) {
        int minEle = arr[i], ind = 0;
        for(int j = i + 1 ; j < size ; j++) {
            if(arr[j] < minEle) {
                minEle = arr[j];
                ind = j;
            }
        }
        if(i != ind) swap(arr[i], arr[ind]);
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

    selectionSort(size, arr);
}