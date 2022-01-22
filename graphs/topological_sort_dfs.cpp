#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define si stack<int>

/*topological sorting => It is a linear ordering of vertices such that
if there is an edge u -> v then u appears before v in that ordering
for implementation purpose we can say that the nodes gets pushed after
performing dfs on the node and pusing inner nodes
and reversing the ans vector in the end
there are many possible topological sort for a graph
condition => Directed Acyclic Graph
*/

/*questions of topological sort will always come in mask form, few hints to pick up
question is on graph directed graph mostly without weight
there is an importance given to ordering
multiple possible orders satisfying the given condition (given by question)
*/

/*
Implementation approach
topological sort is defined only for an acyclic graph
so ensure no cycle
then for each unvisited node perform dfs on its branch node
after that add the current node to the array
*/

void dfs(vvi &graph, int node, vi &ans, vi &vis) {
    vis[node] = 1;
    for (auto x: graph[node]) {
        if (!vis[x]) {
            dfs(graph, x, ans, vis);
        }
    }
    ans.push_back(node);
}


// function to get toposort assuming acyclic graph
vi topo_sort(vvi &graph) {
    int n = graph.size();
    vector <int> vis(n, 0);
    vector <int> ans;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(graph, i, ans, vis);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
