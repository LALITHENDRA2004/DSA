#include<bits/stdc++.h> 
using namespace std;

void print(int size, int arr[]) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[]) {
    for(int i = 0 ; i < size - 1 ; i++) {
        bool swapped = false;
        for(int j = 0 ; j < size - 1 - i ; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
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

    bubbleSort(size, arr);
}