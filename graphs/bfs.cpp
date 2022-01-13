#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define newLine "\n"
# define space " "
// bfs on a graph

void bfs(vvi &graph, vi &vis, int node) {
    // fifo ds is required
    queue <int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty()) {
        int curr_node = q.front();
        q.pop();
        // do something with the node
        cout << curr_node << newLine;
        for (auto x: graph[curr_node]) {
            if (!vis[curr_node]) {
                vis[x] = 1;
                q.push(x);
            }
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

    // start bfs from node 1
    bfs(adj, vis, 0);
}