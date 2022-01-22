#include<bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>

/*
Approach is to use bfs + dp to relax edges constantly
through a node
here we assume that all edges are of unit weight
*/

vi shortest_path(vvi &graph, int src, int n) {
    queue <int> q;
    vi shortDist(n, INT_MAX);

    q.push(src);
    // shortest distance of source from source is 0
    shortDist[src] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        // visit all the connected nodes
        // and try to relax the shortest distance of v using u
        for (auto v: graph[u]) {
            if (shortDist[v] > shortDist[u] + 1) {
                shortDist[v] = shortDist[u] + 1;
                q.push(v);
            }
        }
    }

    return shortDist;
}

int main () {

}