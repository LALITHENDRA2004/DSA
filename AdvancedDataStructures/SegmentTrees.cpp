
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n = 100000;
vector<ll> arr(n), seg(4 * n), lazy(4 * n);

void rangeUpdate(ll ind, ll low, ll high, ll l, ll r, ll val) {
    if(lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if(low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;    }

    if(r < low || l > high || low > high) return;

    if(low >= l && high <= r) {
        seg[ind] += (high - low + 1) * val;
        if(low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        return;
    }

    ll mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll querySum(ll ind, ll low, ll high, ll l, ll r, ll val) {
    if(lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if(low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(r < low || l > high || low > high) return 0;

    if(low >= l && high <= r) {
        return seg[ind];
    }

    ll mid = (low + high) >> 1;
    ll left = querySum(2 * ind + 1, low, mid, l, r, val);
    ll right = querySum(2 * ind + 2, mid + 1, high, l, r, val);
    return left + right;
}

void build(ll ind, ll low, ll high, vector<ll> arr) {
    if(low == high) {
        seg[ind] = arr[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll findMax(ll ind, ll low, ll high, ll l, ll r) {
    if(low >= l && high <= r) {
        return seg[ind];
    }
    if(high < l || low > r) return INT_MIN;
    ll mid = (low + high) / 2;
    ll left = findMax(2 * ind + 1, low, mid, l, r);
    ll right = findMax(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

int main() {

    ll size;
    cin >> size;

    for(ll i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    build(0, 0, size - 1, arr);

    // rangeUpdate(0, 0, 4, 1, 3, 10);
    // cout << querySum(0, 0, 4, 1, 3, 10);
    
    ll q;
    cin >> q;

    while(q--) {
        ll l, r;
        cin >> l >> r;

        cout << findMax(0, 0, size - 1, l, r) << endl;
    }
    
    return 0;
}