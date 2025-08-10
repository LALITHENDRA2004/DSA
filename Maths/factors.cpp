#include<bits/stdc++.h>
using namespace std;

void factors1(int n) {
    for(int i = 1 ; i <= n ; i++) {
        if(n % i == 0) cout << i << " ";
    }
    cout << endl;
}

void factors2(int n) {
    for(int i = 1 ; i * i <= n ; i++) {
        if(n % i == 0) {
            cout << i << " ";
            if(n / i != i) cout << n / i << " ";
        }
    }
    cout << endl;
}

void countFactors(int n) {
    int cnt = 0;
    for(int i = 1 ; i * i <= n ; i++) {
        if(n % i == 0) {
            cnt++;
            if(n / i != i) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;
    factors1(n);
    factors2(n);
    countFactors(n);
    return 0;
}