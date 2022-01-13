#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define newLine "\n"
# define space " "
// dfs on a graph

void dfs(vvi &graph, vi &vis, int node) {
    cout << "visiting node " << node << newLine; 
    for (auto x: graph[node]) {
        if (!vis[x]) {
            vis[x] = 1;
            dfs(graph, vis, x);
        }
    }
}

// pay attention to the nodes of the graph
// if the nodes are numbered 1 - n then we need extra space for index n
int main() {
	int n;
    int edge;
    cin >> n >> edge;

    vvi adj(n);
    vi vis(n, 0);

    // edge is represented as two numbers p,q
    // where edge is from p -> q
    int p,q;
    for (int i=0; i<edge; i++) {
        cin >> p >> q;
        adj[p].push_back(q);
    }

    // start dfs from node 1
    vis[0] = 1;
    dfs(adj, vis, 0);
}