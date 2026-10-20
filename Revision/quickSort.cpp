#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

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

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
}