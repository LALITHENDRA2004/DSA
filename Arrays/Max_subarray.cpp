// Kadane's Algorithm

#include<iostream>
using namespace std;

int main(){
    int A[] = {-2,-3,4,-1,-2,1,6,4};
    int n = sizeof(A) / sizeof(A[0]) ;
    int curr = 0, max_sum = A[0];
    for(int i = 0 ; i < n ; i++){
        curr += A[i];
        if(curr > max_sum) max_sum = curr;
        if(curr < 0) curr = 0;
    }
    cout << "Maximum sum is " << max_sum;
    return 0;
}