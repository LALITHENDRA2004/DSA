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

void dfs(int node, vector<bool> &vis, vector<int> &nodes, vector<vector<int>> &adjList) {
    nodes.push_back(node);
    vis[node] = true;

    for(auto i : adjList[node]) {
        if(vis[i] == false) dfs(i, vis, nodes, adjList);
    }
}

int main() {
    int n, e;
    cout << "Enter the number of nodes and number of edges space seperated: ";
    cin >> n >> e;

    vector<vector<int>> adjList(n + 1);

    for(int i = 0 ; i < e ; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //     1 
    //    / \ 
    //   2   3  
    //  /     \ 
    // 4       5 
    // \       /
    //     6

    display(adjList);

    vector<bool> vis(adjList.size() + 1, false);
    vector<int> nodes;
    dfs(1, vis, nodes, adjList);

    cout << "The Depth First Search Traversal is: " << endl;
    for(int i : nodes) {
        cout << i << " -> ";
    }

    return 0;
}