#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int n) {
    if(i >= n / 2) return true;
    if(s[i] != s[n - 1 - i]) return false;
    return isPalindrome(s, i + 1, n);
}

int main() {
    string s = "madam";
    int n = s.size();
    bool ans = isPalindrome(s, 0, n);
    cout << ans;
    return 0;
}