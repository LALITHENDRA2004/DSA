#include<bits/stdc++.h>
using namespace std;

int n = 100000;
vector<int> arr(n), seg(4 * n);

void build(int ind, int low, int high) {
    if(low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main() {
    int size;
    cin >> size;

    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    build(0, 0, size - 1);

    for(int i = 0 ; i < 4 * size ; i++) {
        cout << seg[i] << " ";
    }
}