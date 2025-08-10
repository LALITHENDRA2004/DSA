#include<bits/stdc++.h>
using namespace std;

void printSubsequences(int i, int arr[], int n, vector<int> nums) {
    if(i == n) {
        for(int i : nums) {
            cout << i << " ";
        }
        if(nums.empty()) cout << "{}";
        cout << endl;
        return;
    }
    
    nums.push_back(arr[i]);
    printSubsequences(i + 1, arr, n, nums);
    
    nums.pop_back();
    printSubsequences(i + 1, arr, n, nums);
}

void printSubsequences(string input, string output) {
    if(input.empty()) {
        cout << output << endl;
        return;
    }

    // include the current character
    printSubsequences(input.substr(1), output + input[0]);

    // do not include the current character
    printSubsequences(input.substr(1), output);
}

int main() {
    string input = "abcd", output = "";

    printSubsequences(input, output);

    int arr[] = {10, 20, 30, 40};
    int n = 4;
    vector<int> nums;
    printSubsequences(0, arr, n, nums);
    return 0;
}