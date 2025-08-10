#include<bits/stdc++.h>
using namespace std;

void printFib(int a, int b, int n) {
    if(n == 0) return;
    int c = a + b;
    cout << c << " ";
    printFib(b, c, n - 1);
}

int main() {
    int a = 0, b = 1, n = 7;
    cout << a << " " << b << " ";
    printFib(a, b, n - 2); // Already 2 terms are printed
    return 0;
}