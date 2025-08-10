// https://cses.fi/problemset/task/1716

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
const ll N = 10000001;

ll fact[N+1];
ll invFact[N+1];

ll mul(int num1, int num2) {
    return ((num1 % mod) * (num2 % mod)) % mod;
}

ll power(ll x, ll n) {
    if(n == 0) return 1;
    if(x == 1 || n == 1) return x;
    ll half = power(x, n / 2);
    ll rem = power(x, n % 2);
    return mul(mul(half, half), rem);
}

void factorial() {
    fact[0] = 1;
    for(ll i = 1 ; i <= N ; i++) {
        fact[i] = mul(i, fact[i - 1]);
    }
}

void invFactorial() {
    invFact[N] = power(fact[N], mod - 2);
    for(ll i = N - 1 ; i >= 0 ; i--) {
        invFact[i] = mul(i + 1, invFact[i + 1]);
    }
}

ll nCr(ll n, ll r) {
    ll ans = mul(fact[n], mul(invFact[r], invFact[n - r]));
    return ans;
}

int main() {
    factorial();
    invFactorial();
    
    ll n, m;
    cin >> n >> m;

    ll ans = nCr(m + n - 1, m);
    cout << ans;

}