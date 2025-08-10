#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(ll a, ll b, ll mod) {
    return ((a % mod) + (b % mod)) % mod;
}

ll sub(ll a, ll b, ll mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll mul(ll a, ll b, ll mod) {
    return ((a % mod) * (b % mod)) % mod;
}

ll pow(ll x, ll n, ll mod) {
    ll res = 1;
    x = x % mod;
    while(n > 0) {
        if(n & 1) res = mul(res, n, mod);
        x = mul(x, x, mod);
        n >> 2;
    }
    return res;
}

ll invMod(ll x, ll mod) {
    return pow(x, mod - 2, mod);
}

struct Hashing {
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 1000000007};
    ll base = 31;
    vector<vector<ll>> powerOfBase;
    vector<vector<ll>> invPowerOfBase;
    vector<vector<ll>> hashValues;
    Hashing(string s1) {
        s = s1;
        n = s.size();
        primes = hashPrimes.size();
        powerOfBase.resize(n + 1);
        invPowerOfBase.resize(n + 1);
        for(int i = 0 ; i < primes ; i++) {
            powerOfBase[i][0] = 1;
            for(int j = 1 ; j <= n ; j++) {
                powerOfBase[i][j] = mul(base, powerOfBase[i][j-1], hashPrimes[i]);
            }

            invPowerOfBase[i][n] = invMod(powerOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1 ; j >= 0 ; j--) {
                invPowerOfBase[i][j] = mul(invPowerOfBase[i][j+1], base, hashPrimes[i]);
            }
        }

        for(int i = 0 ; i < primes ; i++) {
            hashValues.resize(n + 1);
            for(int j = 0 ; j <= n ; j++) {
                hashValues[i][j] = mul((s[j] - 'a' + 1LL), powerOfBase[i][j], hashPrimes[i]);
                hashValues[i][j] = sum(hashValues[i][j], (j > 0LL) ? hashValues[i][j-1] : 0, hashPrimes[i]);
            }
        }

        vector<ll> subStringHash(int l, int r) {
            vector<ll> hash(primes);
            for(int i = 0 ; i < primes ; i++) {
                int val1 = hashValues[i][r];
                int val2 = (i == 0) ? 0LL : hashValues[i][l-1];
                hash[i] = mul(sub(val2, val1, hashPrimes[i]), invPowerOfBase[i][l], hashPrimes[i]);
            }
            return hash;
        }
    }

};

int main() {
    cout << "a";
}