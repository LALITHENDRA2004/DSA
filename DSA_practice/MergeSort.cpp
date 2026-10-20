#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void merge(int low, int mid, int high, int arr[]) {
    vector<int> temp;
    
    int i = low; 
    int j = mid + 1;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= high) temp.push_back(arr[j++]);

    for(int i = low ; i <= high ; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int low, int high, int arr[]) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);
        merge(low, mid, high, arr);
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

    mergeSort(0, size - 1, arr);

    display(arr, size);


}