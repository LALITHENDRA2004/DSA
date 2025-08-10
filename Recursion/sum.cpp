#include<bits/stdc++.h>
using namespace std;

// Function to print the sum of n natural numbers
void sum(int n, int s, int i) {
    if(i > n) {
        cout << s;
        return;
    }
    s += i;
    sum(n, s, i + 1);
}

// Function to return the sum of n natural numbers
int sum(int n) {
    if(n == 1) return 1;
    if(n == 0) return 0;
    return n + sum(n - 1);
}

int main() {
    sum(5, 0, 1);

    cout << endl << sum(5);
    return 0;
}