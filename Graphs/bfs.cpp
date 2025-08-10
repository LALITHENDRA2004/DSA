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

void bfs(vector<vector<int>> &adjList) {
    vector<bool> visited(adjList.size() + 1, false);
    queue<int> q;
    vector<int> nodes;
    
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int node = q.front();
        for(int i = 0 ; i < adjList[node].size() ; i++) {
            int neighbor = adjList[node][i];
            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
        nodes.push_back(node);
        q.pop();
    }

    cout << "Breadth First Search Traversal is: " << endl; 
    for(int i : nodes) {
        cout << i << " -> ";
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

    bfs(adjList);

    return 0;
}