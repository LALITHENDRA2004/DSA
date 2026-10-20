#include<bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int> &arr) {
    vector<int> temp;
    int i = low, j = mid + 1;
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

void divide(int low, int high, vector<int> &arr) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        divide(low, mid, arr);
        divide(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    divide(0, n - 1, arr);

}