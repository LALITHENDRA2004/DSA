#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
        vector<int> rank, parent, size;
        
    public:
        DisjointSet(int n) {
            // rank (assume it as height) is set as 0 initially
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);

            for(int i = 0 ; i <= n ; i++) {
                // each node's parent is the node itself initially
                parent[i] = i;

                // size of each node is the number of nodes from that node to the last level
                size[i] = 1;
            }
        }

        // finding the ultimate parent along with path compression
        int findParent(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

        // performing union by rank
        void unionByRank(int u, int v) {
            // find the ultimate parents of the two nodes u and v
            int up_u = findParent(u);
            int up_v = findParent(v);

            // if the two nodes already belong to the same component, no need to perform union
            if(up_u == up_v) return; 

            // adding the component having less rank to the other component to improve time complexity
            if(rank[up_u] < rank[up_v]) {
                parent[up_u] = up_v;
            }
            else if(rank[up_u] > rank[up_v]) {
                parent[up_v] = up_u;
            }
            else {
                // we can assign the parent as our wish
                parent[up_u] = up_v;

                // rank will be increased only if rank of up_u and up_v are equal 
                // (height will be increased only in this case)
                rank[up_v]++;
            }
        }

        void unionBySize(int u, int v) {
            // find the ultimate parents of the two nodes u and v
            int up_u = findParent(u);
            int up_v = findParent(v);

            // if the two nodes already belong to the same component, no need to perform union
            if(up_u == up_v) return;

            // adding the component having less rank to the other component to improve time complexity
            // size will be increased every time
            if(size[up_u] < size[up_v]) {
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            }
            else {
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }

        void unionOfNodes(int u, int v, int choice) {
            // perform union based on the choice
            if(choice == 1) {
                unionByRank(u, v);
            }
            else {
                unionBySize(u, v);
            }
        }

        void checkIfNodesBelongToTheSameComponent(int node1, int node2) {
            if(findParent(node1) == findParent(node2)) {
                cout << node1 << " and " << node2 << " belong to the same component."; 
            }
            else {
                cout << node1 << " and " << node2 << " does not belong to the same component.";
            }
            cout << endl;
        }
};

int main() {
    // input the nodes and edges 
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // create an instance of DisjointSet 
    DisjointSet ds(nodes);

    // input choice
    int choice;
    cout << "Choose one option: \n";
    cout << "1. Union By Rank\n";
    cout << "2. Union By Size\n";
    cin >> choice;

    // create the disjoint set datastructure
    cout << "Enter " << edges << " edges (nodes range from 1 to " << nodes << "): " << endl;
    for(int i = 0 ; i < edges ; i++) {
        int u, v;
        cin >> u >> v;
        while(u < 1 || u > nodes || v < 1 || v > nodes) {
            cout << "Invalid input! Enter nodes in range 1 to " << nodes << ": ";
            cin >> u >> v;
        }
        ds.unionOfNodes(u, v, choice);
    }
    
    // input queries 
    int queries;
    cout << "Enter the number of queries: ";
    cin >> queries;
    
    // check if the given two nodes belong to the same component
    while(queries--) {
        int node1, node2;
        cout << "Enter any two nodes: ";
        cin >> node1 >> node2;
        while(node1 < 1 || node1 > nodes || node2 < 1 || node2 > nodes) {
            cout << "Invalid input! Enter nodes in range 1 to " << nodes << ": ";
            cin >> node1 >> node2;
        }
        ds.checkIfNodesBelongToTheSameComponent(node1, node2);
    }

    return 0;
}