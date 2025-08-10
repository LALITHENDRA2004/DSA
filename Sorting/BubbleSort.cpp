#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void recursiveBubbleSort(int arr[], int size) {
    if(size > 1) {
        for(int i = 0 ; i < size - 1 ; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        recursiveBubbleSort(arr, size - 1);
    }
}

void bubbleSort(int arr[], int size) {
    display(arr, size);
    // size - 1 passes 
    for(int i = 0 ; i < size - 1 ; i++) {
        cout << "Pass: " << i << endl;
        // Each pass maximum element will be placed from last 
        bool swapped = false;
        // till size - 1 - i because last element which is sorted will be at 
        // size - i and we compare till < size - i - 1
        for(int j = 0 ; j < size - i - 1 ; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        display(arr, size);
        if(swapped == false) break; 
    }
}

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the array elements : ";
    for(int i = 0 ; i < size ; i++) cin >> arr[i];
    cout << "Before sorting : ";
    display(arr, size);
    cout << "Select : " << endl << "1. Iterative" << endl << "2. Recursive" << endl;
    int select;
    cin >> select;
    if(select == 1) {
        bubbleSort(arr, size);
    }
    else {
        recursiveBubbleSort(arr, size);
    }
    cout << "After sorting : ";
    display(arr, size);
    return 0;
}