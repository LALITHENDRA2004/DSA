#include<bits/stdc++.h> 
using namespace std;

void print(vector<int> &arr) {
    for(int i = 0 ; i < arr.size() ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int low, int high, vector<int> &arr) {
    int pivot = arr[low];

    int i = low, j = high;
    while(i < j) {
        while(i < high && arr[i] <= pivot) i++;
        while(j > low && arr[j] > pivot) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int low, int high, vector<int> &arr) {
    if(low < high) {
        int partitionInd = partition(low, high, arr);
        quickSort(low, partitionInd - 1, arr);
        quickSort(partitionInd + 1, high, arr);
    }
}

int main() {
    int size; 
    cin >> size;

    vector<int> arr(size);

    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    quickSort(0, size-1, arr);

    print(arr);
}