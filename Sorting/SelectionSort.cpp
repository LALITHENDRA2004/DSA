#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void recursiveSelectionSort(int arr[], int size) {
    if(size > 1) {
        int maxEle = arr[0];
        int loc = 0;
        for(int i = 1 ; i < size ; i++) {
            if(arr[i] > maxEle) {
                maxEle = arr[i];
                loc = i;
            }
        }
        swap(arr[loc], arr[size-1]);
        recursiveSelectionSort(arr, size - 1);
    }
}

// Fixing the position of minimum element everytime
void selectionSort1(int arr[], int size) {
    for(int i = 0 ; i < size - 1 ; i++) {
        cout << "Pass: " << i << endl;
        int minInd = i;
        for(int j = i + 1 ; j < size ; j++) {
            if(arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        if(minInd != i) swap(arr[i], arr[minInd]);

        display(arr, size);
    }
}

// Fixing the position of maximum element everytime
void selectionSort2(int arr[], int size) {
    for(int i = 0 ; i < size - 1 ; i++) {
        int maxEle = arr[0], loc = 0;
        for(int j = 1 ; j < size - i ; j++) {
            if(arr[j] > maxEle) {
                maxEle = arr[j];
                loc = j;
            }
        }
        swap(arr[loc], arr[size - 1 - i]);
    }
}

int main() {
    int size;
    cout << "Enter the size : ";
    cin >> size;
    int arr[size];
    cout << "Enter any " << size <<  " elements : ";
    for(int i = 0 ; i < size ; i++) cin >> arr[i];
    cout << "Before sorting : ";
    display(arr, size);
    cout << "Select : " << endl << "1. Selection sort fixing the position of smallest element everytime" << endl << "2. Selection sort fixing the position of largest element everytime" << endl << "3. Recursive Selection sort" << endl;
    int selected; 
    cin >> selected;
    if(selected == 1) {
        selectionSort1(arr, size);
    }
    else if(selected == 2) {
        selectionSort2(arr, size);
    }
    else {
        recursiveSelectionSort(arr, size);
    }
    cout << "After sorting : ";
    display(arr, size);
    return 0;
}