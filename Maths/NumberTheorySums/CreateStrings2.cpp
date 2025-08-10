// https://cses.fi/problemset/result/12205113/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
const ll N = 1000001;

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

int main() {
    factorial();
    invFactorial();
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s) {
        mp[i]++;
    }

    ll ans = 1;
    ans = mul(ans, fact[s.size()]);

    for(auto i : mp) {
        ans = mul(ans, invFact[i.second]);
    }

    cout << ans;

}