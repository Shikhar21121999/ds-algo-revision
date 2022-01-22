#include<bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>
# define si stack <int>

/*topological sorting => It is a linear ordering of vertices such that
if there is an edge u -> v then u appears before v in that ordering
for implementation purpose we can say that the nodes gets pushed after
performing dfs on the node and pusing inner nodes
and reversing the ans vector in the end
there are many possible topological sort for a graph
condition => Directed Acyclic Graph
*/

/*
Approach for Kahn's algo is derived from the fact that
nodes with lower in degree appear earlier in the order
we can also observe that nodes with 0 in degree appear first
So we keep on adding nodes whose in degree have become zero
at the same time decreasing in degree of adjacent nodes
adding nodes whose in degree have become 0 to q for bfs traversal
*/

// function to find toposort
vi topo_sort(vvi &graph) {
    int n = graph.size();
    vi ans;
    vi indegree(n, 0);
    
    for (auto vec: graph) {
        for (auto v: vec) {
            indegree[v]++;
        }
    }

    queue <int> q;

    // add all the nodes whose in degree is zero
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // perform bfs and keep adding nodes with indgree 0 to q
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto v: graph[curr]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return ans;
}