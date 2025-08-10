#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &adjList) {
    for(int node = 1 ; node < adjList.size() ; node++) {
        cout << node << " -> ";
        for(int neighbour = 0 ; neighbour < adjList[node].size() ; neighbour++) {
            cout << adjList[node][neighbour] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adjList(n + 1);

    for(int i = 0 ; i < e ; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    display(adjList);

    // Time Complexity: O(e)
    // Space Complexity: 
    // -> O(n + 2 * e) for undirected graph but in big - O it is considered 
    //    as O(n + e)
    // -> O(n + e) for directed graph
}