#include<bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>
# define si stack <int>

// function to perform dfs and fill ans
// returns true if cycle is found else false
bool dfsCycle(vvi &graph, int node, vi &ans, vi &vis) {
    vis[node] = 1; // mark as gray
    for (auto x: graph[node]) {
        if (!vis[x] && dfsCycle(graph, x, ans, vis)) {
            return true;
        } else if (vis[x] == 1) {
            return true;
        }
    }
    vis[node] = 2;
    ans.push_back(node);
    return false;
}

// function to find toposort and if cyclic return empty array
vi topo_sort(vvi &graph) {
    int n = graph.size();
    vi vis(n, 0);
    vi ans;
    bool cyclic = false;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfsCycle(graph, i, ans, vis)) {
            cyclic = true;
        }
    }
    if (cyclic) {
        cout << "Cyclic Invalid toposort";
        return vi {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
}