#include<bits/stdc++.h>
using namespace std;

int recBinarySearch(int low, int high, vector<int> &arr, int key) {
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(key == arr[mid]) return mid;
    else if(key < arr[mid]) {
        return recBinarySearch(low, mid - 1, arr, key);
    }
    else {
        return recBinarySearch(mid + 1, high, arr, key);
    }
}

int binarySearch(vector<int> arr, int key) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(key == arr[mid]) {
            return mid;
        }
        else if(key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
    
}

int main() {
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;

    vector<int> arr(len);
    cout << endl << "Enter the elements: ";
    for(int i = 0 ; i < len ; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to be found: ";
    int key;
    cin >> key;

    int ind1 = binarySearch(arr, key);
    cout << ind1 << endl;

    int ind2 = recBinarySearch(0, len - 1, arr, key);
    cout << ind2;

}