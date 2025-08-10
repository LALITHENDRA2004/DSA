#include<bits/stdc++.h>
using namespace std;

void printNPrimes(int n) {
    vector<int> prime(n + 1, true);

    for(int i = 2 ; i * i <= n ; i++) {
        if(prime[i] == true) {
            for(int j = i * i ; j <= n ; j += i) {
                prime[j] = false;
            }
        }
    }

    for(int i = 2 ; i <= n ; i++) {
        if(prime[i]) cout << i << " ";
    }
    cout << endl;
}

void countPrimes(int n) {
    vector<int> prime(n + 1, true);

    for(int i = 2 ; i * i <= n ; i++) {
        if(prime[i] == true) {
            for(int j = i * i ; j <= n ; j += i) {
                prime[j] = false;
            }
        }
    }

    int cnt = 0;
    for(int i = 2 ; i <= n ; i++) {
        if(prime[i] == true) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;
    printNPrimes(n);
    countPrimes(n);
}