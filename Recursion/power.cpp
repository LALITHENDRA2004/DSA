#include<bits/stdc++.h>
using namespace std;

// Height of stack is n
int power1(int x, int n) {
    if(n == 0) return 1;
    if(x == 1) return x;
    return x * power1(x, n - 1);
    
}


// Height of stack is log n
int power2(int x, int n) {
    if(n == 0) return 1;
    if(x == 0) return 0;

    if(n % 2 == 0) {
        return power2(x, n / 2) * power2(x, n / 2);
    }
    else {
        return power2(x, n / 2) * power2(x, n / 2) * x;
    }
}

int power3(int x, int n) {
    if(n == 0) return 1;
    if(x == 1) return 1;
    if(n % 2 != 0) {
        return x * power3(x, n - 1);
    }
    else {
        return power3(x * x, n / 2);
    }
}

int main() {
    int x = 2, n = 5;
    int ans1 = power1(x, n);
    cout << ans1 << endl;
    
    int ans2 = power2(x, n);
    cout << ans2 << endl;

    int ans3 = power3(x, n);
    cout << ans3;

    return 0;
}