#include<bits/stdc++.h>
using namespace std;

void print1(int i, int n) {
    if(i > n) return;
    cout << i << " ";
    print1(i + 1, n);
}

void print2(int n) {
    if(n == 0) return;
    cout << n << " ";
    print2(n - 1);
}

void print3(int n) {
    if(n == 0) return;
    print3(n - 1);
    cout << n << " ";
}

void print4(int i, int n) {
    if(i > n) return;
    print4(i + 1, n);
    cout << i << " ";
}

int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);
}

void sum1(int n, int sum) {
    if(n == 0) {
        cout << sum;
        return;
    }
    sum += n;
    sum1(n - 1, sum);
}

int factorial(int n) {
    if(n == 0 or n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int i = 1, n = 5;

    print1(i, n);
    cout << endl;

    print2(n);
    cout << endl;

    print3(n);
    cout << endl;

    print4(i, n);
    cout << endl;

    cout << sum(n);
    cout << endl;

    sum1(5, 0);
    cout << endl;

    cout << factorial(5);
    return 0;
}