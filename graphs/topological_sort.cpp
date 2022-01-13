#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define si stack<int>

// topological sorting => It is a linear ordering of vertices such that
// if there is an edge u -> v then u appears before v in that ordering
// there are many possible topological sort for a graph
// condition => Directed Acyclic Graph

// questions of topological sort will always come in mask form, few hints to pick up
// question is on graph directed graph mostly without weight
// there is an importance given to ordering
// multiple possible orders satisfying the given condition (given by question)

bool topologicalSortDfs(vvi &graph, vi &vis, int node, vi &order) {
    vis[node] = 1; // represent gray 
    for (auto x: graph[node]) {
        // visit the unvisited nodes (vis[x] = 0)
        if (vis[x] == 0) {
            if (topologicalSortDfs(graph, vis, x, order)) {
                return true;
            }
        } else if(vis[x] == 1) {
            // do we find a node already visited (gray colored)
            return true;
        }
    }
    order.push_back(node);
    return false;
}

// find topological order (sort) if n nodes are given numbered 0 to n-1
// and edges are given
vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
    // create a adjacency list graph
    vvi adj(n);

    for (auto x: edges) {
        adj[x[0]].push_back(x[1]);
    }

    // helper storage
    vi vis(n,0);
    vi order;
    bool isCyclic = false;

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && topologicalSortDfs(adj, vis, i, order)) {
            isCyclic = true;
            break;
        }
    }
    if (isCyclic) {
        return vi {};
    } else {
        reverse(order.begin(), order.end());
        return order;
    }
}

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

    bool isCyclic = false;
    
}