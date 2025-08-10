#include<bits/stdc++.h>
using namespace std;

void printSubsequencesWhoseSumIsK(int i, int arr[], vector<int> ds, int n, int k, int sum) {
    if(i == n) {
        if(sum == k) {
            cout << "[";
            for(int i : ds) {
                cout << i << " ";
            }
            if(ds.empty()) cout << "{}";
            cout << "]" << endl;
        }
        return;
    }

    ds.push_back(arr[i]);
    sum += arr[i];
    printSubsequencesWhoseSumIsK(i + 1, arr, ds, n, k, sum);
    
    ds.pop_back();
    sum -= arr[i];
    printSubsequencesWhoseSumIsK(i + 1, arr, ds, n, k, sum);
}


bool printSubsequenceWhoseSumIsK(int i, int arr[], vector<int> ds, int n, int k, int sum) {
    if(i == n) {
        if(sum == k) {
            cout << "[";
            for(int i : ds) {
                cout << i << " ";
            }
            if(ds.empty()) cout << "{}";
            cout << "]" << endl;
            return true;
        }
        return false;
    }
    
    ds.push_back(arr[i]);
    sum += arr[i];
    if(printSubsequenceWhoseSumIsK(i + 1, arr, ds, n, k, sum) == true) return true;
    
    ds.pop_back();
    sum -= arr[i];
    if(printSubsequenceWhoseSumIsK(i + 1, arr, ds, n, k, sum) == true) return true;

    return false;
}


int countOfSubsequencesWhoseSumIsK(int i, int arr[], int n, int k, int sum, int cnt) {
    if(sum > k) return 0;
    if(i == n) {
        if(sum == k) {
            cnt++;
            return 1;
        }
        return 0;
    }

    sum += arr[i];
    int x = countOfSubsequencesWhoseSumIsK(i + 1, arr, n, k, sum, cnt);

    sum -= arr[i];
    int y = countOfSubsequencesWhoseSumIsK(i + 1, arr, n, k, sum, cnt);

    return x + y;
}

int main() {
    int arr[] = {1, 2, 1, 3, 1};
    int i = 0, k = 3, n = 5, sum = 0;
    vector<int> ds;
    
    cout << "Printing all the subsequences whose sum is k : " << endl;
    printSubsequencesWhoseSumIsK(i, arr, ds, n, k, sum);
    cout << endl;

    cout << "Printing only one subsequence whose sum is k: " << endl;
    printSubsequenceWhoseSumIsK(i, arr, ds, n, k, sum);

    cout << "Count of subsequences whose sum is k: " << endl;
    int ans = countOfSubsequencesWhoseSumIsK(i, arr, n, k, sum, 0);
    cout << ans;
}