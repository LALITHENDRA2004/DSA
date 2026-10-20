#include<bits/stdc++.h> 
using namespace std;

void print(vector<int> &arr) {
    for(int i = 0 ; i < arr.size() ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int low, int mid, int high, vector<int> &arr) {
    int li = low, ri = mid + 1;
    vector<int> temp;
    while(li <= mid && ri <= high) {
        if(arr[li] <= arr[ri]) {
            temp.push_back(arr[li++]);
        }
        else {
            temp.push_back(arr[ri++]);
        }
    }

    while(li <= mid) {
        temp.push_back(arr[li++]);
    }

    while(ri <= high) {
        temp.push_back(arr[ri++]);
    }

    for(int i = low ; i <= high ; i++) {
        arr[i] = temp[i-low];
    }
}

void mergeSort(int low, int high, vector<int> &arr) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid, arr);
        mergeSort(mid+1, high, arr);

        merge(low, mid, high, arr);
    }
}

int main() {
    int size; 
    cin >> size;

    vector<int> arr(size);

    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    mergeSort(0, size-1, arr);

    print(arr);
}