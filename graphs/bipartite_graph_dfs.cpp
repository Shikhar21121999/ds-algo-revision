#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>
#define si stack <int>
#define qi queue <int>

/*
Check if a graph is bipartite
A bipartite graph is a graph whose vertices can be divided into two disjoint
sets so that every edge connects two vertices from different sets that is 
there is no edge which connects vertices from the same set
*/

/*
If a graph has odd length cycle, then it is not a bipartite graph
if it does not have a odd length cycle it is a bipartite graph
*/

/*
Here we try to color adjacent nodes with different colors
if at any point it is not possible, that is we encounter a
dest node which is colored same as src node, we say
not bipartite
*/

bool bipartiteDFS(vvi &adj, vi &color, int src) {

    for (auto dest: adj[src]) {
        if (color[dest] == -1) {
            color[dest] = color[src] ^ 1;
            if (!bipartiteDFS(adj, color, dest)) {
                return false;
            }
        } else if (color[dest] == color[src]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vvi &adj, int n) {
    // -1 represent un-colored, 0 and 1 repersent different colors
    vi color(n, -1);

    // perform bfs for all the uncolored nodes
    for(int i = 0; i < n; i++) {
        if (color[i] == -1 ) {
            color[i] = 1;
            if (!bipartiteDFS(adj, color, i)) {
                return false;
            }
        }
    }
    return true;
}

// general function to denote nodes in a graph
// numbered from 0
// and get edges from user
int main() {
    int n;
    int node1, node2;
    cin >> n;
    vector < vector <int> > edges;
    // input edges
    for (int i = 0; i < n; i++) {
        cin >> node1 >> node2;
        edges.push_back(vector <int> {node1, node2});
    }

    // create a graph 
    vvi adj(n);
    for (auto x: edges) {
        // directed
        adj[x[0]].push_back(x[1]);
    }
}