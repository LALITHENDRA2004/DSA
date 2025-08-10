#include<bits/stdc++.h>
using namespace std;

void primeFactorization1(int n) {
    for(int i = 2 ; i * i <= n ; i++) {
        while(n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if(n > 1) cout << n << " ";
    cout << endl;
}

vector<int> createSPF(int n) {
    vector<int> spf;
    for(int i = 0 ; i <= n ; i++) spf.push_back(i);

    for(int i = 2 ; i * i <= n ; i++) {
        for(int j = i * i ; j <= n ; j += i) {
            if(j == spf[j]) spf[j] = i;
        }
    }
    return spf;
}

// Prime Factorization using Smallest Prime Factor(SPF) Array
void primeFactorization2(int n) {
    vector<int> spf = createSPF(n);

    while(n != 1) {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

int main() {
    int n;
    cin >> n;
    primeFactorization1(n);
    primeFactorization2(n);
    return 0;
}