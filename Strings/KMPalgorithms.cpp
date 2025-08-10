#include<bits/stdc++.h>
using namespace std;

void formLPSArray(string pattern, int p, vector<int> &lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < p) {
        if(pattern[len] == pattern[i]) {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else {
            if(len != 0) {
                len = 0;
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(string text, string pattern) {
    int t = text.size();
    int p = pattern.size();
    vector<int> lps(p, 0);
    formLPSArray(pattern, p, lps);
    lps = {0, 0, 0, 1, 2, 0};
    int i = 0, j = 0;
    while(i < t) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if(j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
        if(j == p) {
            cout << i - p;
            j = lps[j - 1];
        }
    }
}

int main() {
    string text = "onionionspl";
    string pattern = "onions";
    KMPsearch(text, pattern);
    return 0;
}