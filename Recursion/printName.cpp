#include<bits/stdc++.h>
using namespace std;

void printName(int i, int n) {
    if(i == n) return;
    cout << "Lalithendra" << endl;
    printName(i + 1, n);
}

int main() {
    int n = 5;
    printName(0, 5);
    return 0;
}