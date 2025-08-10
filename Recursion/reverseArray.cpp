#include<bits/stdc++.h>
using namespace std;

void reverse1(vector<int> &arr, int i, int j) {
    if(i >= j) return;
    swap(arr[i], arr[j]);
    reverse1(arr, i + 1, j - 1);
}

void reverse2(vector<int> &arr, int i, int n) {
    if(i >= n / 2) return;
    swap(arr[i], arr[n - 1 - i]);
    reverse2(arr, i + 1, n);
}

int main() {
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {10, 20, 30, 40, 50};
    int i = 0, j = arr1.size() - 1;
    reverse1(arr1, i, j);

    for(int i : arr1) {
        cout << i << " ";
    }
    cout << endl;

    i = 0;
    int n = arr2.size();
    reverse2(arr2, i, n);

    for(int i : arr2) {
        cout << i << " ";
    }
    return 0;
}