#include<bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>
# define si stack <int>

/*
Topological sorting is only possible for Directed Acyclic Graph
If there is a cycle in the graph TopoSort for it should not be possible
TopoSort not possible means that number of elements in TopoSort is not equal
to N
basically we can say if cyclic number of elements in topoSort will
not be equal to N
else cyclic
*/

bool cyclic(vvi &graph) {
    int n = graph.size();
    vi vis(n, 0);
    vi indegree(n, 0);
    int cnt = 0;
    
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
        cnt++;

        for (auto v: graph[curr]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    // cnt == n means topoSort possible hence no cycle
    // otherwise cyclic
    return !(cnt == n);
}