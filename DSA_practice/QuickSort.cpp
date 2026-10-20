#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int partition(int low, int high, int arr[]) {
    int pivot = arr[low];

    int i = low;
    int j = high;
    
    while(i < j) {
        while(arr[i] <= pivot && i < high) {
            i++;
        }

        while(arr[j] > pivot && j > low) {
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    
    return j;
}

void quickSort(int low, int high, int arr[]) {
    if(low < high) {
        int pos = partition(low, high, arr);
        quickSort(low, pos - 1, arr);
        quickSort(pos + 1, high, arr);
    }
}

int main() {
    cout << "Enter the size of the array: ";
    int size; 
    cin >> size;

    cout << "Enter " << size << " elements: ";
    int arr[size];
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    quickSort(0, size - 1, arr);

    display(arr, size);
}