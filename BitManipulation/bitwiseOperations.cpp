#include<bits/stdc++.h>
using namespace std;

void line(int n) {
    while(n != 0) {
        cout << "-";
        n--;
    }
    cout << endl;
}

string seperate(string s) {
    string ans = "";
    for(int i = 0 ; i < s.size() ; i++) {
        ans = ans + s[i] + " ";
    }
    return ans;
}

string format(string s) {
    int numberOfZeroes = 32 - s.size();
    while(numberOfZeroes != 0) {
        s = "0" + s;
        numberOfZeroes--;
    }
    return s;
}

string binary(int num) {
    string bin = "";
    while(num != 1) {
        bin += to_string(num % 2);
        num = num / 2;
    }
    bin += "1";
    reverse(bin.begin(), bin.end());
    return bin;
}

int decimal(string bin) {
    int ind = bin.size() - 1, power = 1, num = 0;
    for(int i = ind ; i >= 0 ; i--) {
        num = num + (bin[i] - '0') * power;
        power = power * 2;
    }
    return num;
}

void AND(int num1, int num2) {
    string first = binary(num1);
    string second = binary(num2);
    
    first = format(first);
    second = format(second);

    while(first[0] == '0' && second[0] == '0') {
        first.erase(first.begin());
        second.erase(second.begin());
    }
    
    string ans = "";
    int size = first.size();
    for(int i = size - 1 ; i >= 0 ; i--) {
        if(first[i] == '1' && second[i] == '1') {
            ans = "1" + ans;
        }
        else {
            ans = "0" + ans;
        }
    }
    
    first = seperate(first);
    second = seperate(second);
    ans = seperate(ans);
    
    cout << "   " << first << " (" << num1 << ")" << endl << " & " << second << " (" << num2 << ")"<< endl << "   ";
    line(first.size());
    cout << "   " << ans << " (" << (num1 & num2) << ")";
}


void OR(int num1, int num2) {
    string first = binary(num1);
    string second = binary(num2);
    
    first = format(first);
    second = format(second);

    while(first[0] == '0' && second[0] == '0') {
        first.erase(first.begin());
        second.erase(second.begin());
    }
    
    string ans = "";
    int size = first.size();
    for(int i = size - 1 ; i >= 0 ; i--) {
        if(first[i] == '1' || second[i] == '1') {
            ans = "1" + ans;
        }
        else {
            ans = "0" + ans;
        }
    }
    
    first = seperate(first);
    second = seperate(second);
    ans = seperate(ans);
    
    cout << endl << endl << "   " << first << " (" << num1 << ")" << endl << " & " << second << " (" << num2 << ")"<< endl << "   ";
    line(first.size());
    cout << "   " << ans << " (" << (num1 | num2) << ")";
}

void NOT(int n) {
    string num = binary(n);
    num = format(num);
    num = seperate(num);

    // 1. Flip all the bits
    // 2. If the number is negative convert it into it's 2's complement form
    // 3. The answer will be the negative of decimal form of the number

    // Note: ~n = -(n + 1)

    cout << num << endl;

    cout << endl << "After flipping:" << endl;

    for(int i = 0 ; i < num.size() ; i++) {
        if(num[i] == '0') num[i] = '1';
        else if(num[i] == '1') num[i] = '0';
    }

    cout << num << endl;

    // The most sigificant bit (MSB) is 1. It indicates the negative sign. Actually a negative number is
    // stored in the form of it's 2's complement. Suppose 1101 is the number in binary let the MSB denotes
    // the sign. The number is stored in it's 2's complement form which means:

    //          1 1 0 1  = (-2^3 + 2^2 + 0 + 2^0)

    //  1's ->  0 0 1 0

    //  2's ->  0 0 1 0 + 1 = 0 0 1 1 = -(0 + 0 + 2^1 + 2^0) = -3
    cout << "~5 = " << ~n;



    
}

int main() {
    // AND(10, 34);
    // OR(10, 34);

    NOT(5);
    return 0;
}
