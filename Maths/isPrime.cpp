#include<bits/stdc++.h>
using namespace std;

void isPrime1(int n) {
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++) {
        if(n % i == 0) {
            cnt++;
        }
    }
    if(cnt == 2) cout << n << " is prime";
    else cout << n << " is not prime";
    cout << endl;
}

void isPrime2(int n) {
    bool flag = true;
    for(int i = 2 ; i < n ; i++) {
        if(n % i == 0) {
            flag = false;
            break;
        }
    }
    if(n == 1) cout << n << " is not prime";
    else if(flag == true) cout << n << " is prime";
    else cout << n << " is not prime";
    cout << endl;
}

void isPrime3(int n) {
    bool flag = true;
    for(int i = 2 ; i * i <= n ; i++) {
        if(n % i == 0) {
            flag = false;
            break;
        }
    }
    if(n == 1) cout << n << " is not prime";
    else if(flag == true) cout << n << " is prime";
    else cout << n << " is not prime";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    isPrime1(n);
    isPrime2(n);
    isPrime3(n);
}