#include<iostream>
using namespace std;

int main(){
    int A[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(A) / sizeof(A[0]);
    int low = 0, high = n - 1, mid = 0;
    while(low < high and mid <= high) {
        if(A[mid] == 0) {
            swap(A[low], A[mid]);
            low += 1;
            mid += 1;
        }
        else if(A[mid] == 1) mid += 1;
        else if(A[mid] == 2) {
            swap(A[mid],A[high]);
            high -= 1;
        }

    }

    for(int i = 0 ; i < n ; i++) cout << A[i] <<" ";

    return 0;
}