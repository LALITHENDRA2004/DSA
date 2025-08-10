#include<bits/stdc++.h>
using namespace std;

// printing the factorial of a number (two variables)
void factorial1(int n, int f) {
    if(n == 0) {
        cout << f;
        return;
    }
    f *= n;
    factorial1(n - 1, f);
}

// returnnig the factorial of a number (one variable)
int factorial2(int n) {
    if(n == 1 or n == 0) {
        return 1;
    }
    return n * factorial2(n - 1);
}

int main() {
    factorial1(0, 1);
    cout << endl;

    cout << factorial2(0);
    return 0;
}