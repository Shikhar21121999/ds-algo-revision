#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define newLine "\n"
# define space " "
// dfs on a graph with modification to check if cycle exists (only check)

/*
Cycle exists in a graph if we are able to reach a node
on which we performed dfs in the first place
if we are reaching a node which is already visited but node from its dfs
then cycle does not exists

1 -> 2 -> 3
     |    |
     5 <- 4
          |
6 -> 7 -> 8
here 12345 is a cycle
but 6785 is not a cycle
for implementation when we start dfs on a node we mark it as gray
denoting that this node is visited but dfs is not complete
if we reach a node with vis = 1 denotes that we have reached this node
when dfs is not complete on it thereby a cycle
but if we reach a node with vis = 2 then not a cycle
*/

bool dfsCycle(vvi &graph, vi &vis, int node) {
    vis[node] = 1; // represent gray 
    for (auto x: graph[node]) {
        // visit the unvisited nodes (vis[x] = 0)
        if (vis[x] == 0) {
            // perform dfs on unvisited node
            if (dfsCycle(graph, vis, x)) {
                return true;
            }
        } else if(vis[x] == 1) {
            // we found a node, dfs on which is not complete
            // thereby a cycle
            return true;
        }
    }
    // dfs on node complete
    vis[node] = 2;
    return false;
}

bool isCyclic(vvi &adj, int n) {
    vi vis(n, 0);

    // perform dfs on nodes which are not yet visited
    for (int i=0; i < n; i++) {
        // this checks if we found a cycle on un-visited node
        if (vis[i] == 0 && dfsCycle(adj, vis, i)) {
            return true;
        }
    }
    return false;
}

// pay attention to the nodes of the graph
// if the nodes are numbered 1 - n then we need extra space for index n
int main() {
	int n;
    int edge;
    cin >> n >> edge;

    vvi adj(n);
    

    // edge is represented as two numbers p,q
    // where edge is from p -> q
    int p,q;
    for (int i=0; i<edge; i++) {
        cin >> p >> q;
        adj[p].push_back(q);
    }

    cout << isCyclic(adj, n);

}