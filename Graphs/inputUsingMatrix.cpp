#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> matrix) {
    for(auto arr : matrix) {
        for(auto ele : arr) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e; // n -> number of nodes, e -> number of edges
    cin >> n >> e;
    vector<vector<int>> matrix(n + 1, vector<int> (n + 1));
    for(int i = 0 ; i < e ; i++) {
        int u, v;
        cin >> u >> v; // There is an edge between u and v nodes
        matrix[u][v] = 1;
    }

    display(matrix);

    // Time Complexity: O(e)
    // Space Complexity: O(n^2) -> Too costly

}