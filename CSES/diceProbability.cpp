#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<vector<ll>> dp(n + 1, vector<ll> (b + 1, 0));

    for(ll i = 1 ; i <= 6 ; i++) {
        dp[1][i] = 1;
    }


    for(ll i = 2 ; i <= n ; i++) {
        for(ll t = 1 ; t <= b ; t++) {
            for(ll d = 1 ; d <= 6 ; d++) {
                if(t >= d) dp[i][t] += dp[i - 1][t - d];
            }
        }
    }

    for(auto arr : dp) {
        for(int i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }

    ll fav = 0;
    for(ll i = a ; i <= b ; i++) {
        fav += dp[n][i];
    }

    double ans1 = fav;
    cout << fav << endl;
    for(int i = 1 ; i <= n ; i++) {
        ans1 = ans1 / 6;
        //cout << ans1 << endl;
    }

    printf("%.6f", ans1);
    return 0;
}