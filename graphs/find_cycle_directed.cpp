#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define newLine "\n"
# define space " "

// check if cycle exits in graph if it does print the cycle,
// print any cycle

/*
Implementation is basically checking for cycle if exists
we maintain an array to store the parent children relation between nodes
when a cycle is found we mark the end and start of the cycle
we then later trace back from end till we reach the start using parent
thereby getting the cycle
*/

bool dfsCycle(vvi &graph, vi &vis, vi &parent, int node, int &cycleStart, int &cycleEnd) {
    // we are beginning dfs on this so mark it as gray
    vis[node] = 1;

    for(auto x: graph[node]) {
        // if unvisited and cycle found on node
        if (vis[x] == 0) {
            parent[x] = node;
            if (dfsCycle(graph, vis, parent, x, cycleStart, cycleEnd)) {
                return true;
            }
        } else if (vis[x] == 1){
            cycleEnd = node;
            cycleStart = x;
            return true;
        }
    }
    vis[node] = 2;
    return false;
}

vector <int> getCycle(vvi &adj, int n) {

    // check if cycle exists and get start and end point
    vi vis(n,0);
    vi parent(n, -1);
    int cyclestart;
    int cycleEnd;

    bool cyclic = false;
    for(int i = 0; i < n; i++) {
        if (vis[i] == 0 and dfsCycle(adj, vis, parent, i, cyclestart, cycleEnd)) {
            // cycle found
            cyclic = true;
            break;
        }
    }

    if (!cyclic) {
        return {-1};
    }
    // what we need to do is go from cycle end to cycleStart
    // while appending nodes into an array, at the end
    // we can reverse the array
    vi cyclePath;
    cyclePath.push_back(cyclestart);
    for (int v=cycleEnd; v != cyclestart; v = parent[v]) {
        cyclePath.push_back(v);
    }
    cyclePath.push_back(cyclestart);
    // reverse the cyclePath
    reverse(cyclePath.begin(), cyclePath.end());
    return cyclePath;
}

// general function to denote nodes in a graph
// numbered from 0
// and get edges from user
int main() {
    int n;
    int node1, node2;
    cin >> n;
    vector < vector <int> > edges;
    for (int i = 0; i < n; i++) {
        cin >> node1 >> node2;
        edges.push_back(vector <int> {node1, node2});
    }

    // create undirected graph adjacency list representation
    vvi adj(n);

    for (auto x: edges) {
        adj[x[0]].push_back(x[1]);
    }

    // abstract function for creating cycle
    vector <int> cycle = getCycle(adj, n);
}