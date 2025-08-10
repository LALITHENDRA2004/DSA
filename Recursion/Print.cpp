#include<bits/stdc++.h>
using namespace std;

void printReverse(int n) {
    if(n == 0) return;
    cout << n << " ";
    printReverse(n - 1);
}

// printing of 1 to n using 2 variables
void print1(int n, int i) {
    if(i > n) return;
    cout << i << " ";
    print1(n, i + 1);
}

// printing of 1 to n using 1 variable
void print2(int n) {
    if(n < 1) return;
    print2(n - 1);
    cout << n << " ";
}

int main() {
    printReverse(5);
    cout << endl;

    print1(5, 1);
    cout << endl;

    print2(5);
    return 0;
}