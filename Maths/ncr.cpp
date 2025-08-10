// Fermat's Little Theorem:

// Let us consider two numbers x and p such that x is not divisible by p, then
// power(x, p - 1) congruent to 1 mod p

// Using this statement, we can find the value of inverse of a number

// consider the equation 
// power(x, p - 1) = 1 mod p

// divide with x on both sides
// power(x, p - 2) = inverse(x) mod p

// Conclusion:

// inverse(x) = power(x, p - 2) mod p 

// similarly, invFact[N] = power(fact[N], p - 2) mod p;

// ------------------------------------------------------------------------------------------------------

// Another formula for inverse of a number 

// inverse(x!) = (1 / x!) * (x + 1)! / (x + 1)!
//            = (1 / x!) * ((x + 1) * x!) / (x + 1)!
//            = (x + 1) / (x + 1)!
//            = (x + 1) * inverse((x + 1)!)


// Conclusion:

// inverse(x!) = (x + 1) * inverse((x + 1)!)



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1000000;
const ll mod = 1000000007;

ll fact[N + 1];
ll invFact[N + 1];
ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
void factorial() {
    fact[0] = 1;
    for(ll i = 1 ; i <= N ; i++) {
        fact[i] = mul(i, fact[i-1]);
    }
}

ll power(ll x, ll n) {
    if(n == 0 || x == 1) return 1;
    if(n == 1) return x;
    ll half = power(x, n / 2);
    ll rem = power(x, n % 2);
    return mul(mul(half, half), rem);
}

void inverseFactorial() {
    invFact[N] = power(fact[N], mod - 2) % mod;
    for(ll i = N - 1 ; i >= 0 ; i--) {
        invFact[i] = mul(i+1, invFact[i+1]);
    }
}

ll nCr(ll n, ll r) {
    ll ans = mul(fact[n], mul(invFact[r], invFact[n-r]));
    return ans;
}

int main() {

    factorial();
    inverseFactorial();

    ll n, r;
    cin >> n >> r;

    ll ans = nCr(n, r);
    cout << ans;

}
