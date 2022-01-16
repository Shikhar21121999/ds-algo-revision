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

bool isBipartite(vvi &edges, int n) {
    // create a graph 
    vvi adj(n);
    for (auto x: edges) {
        // directed
        adj[x[0]].push_back(x[1]);
    }

    // -1 represent un-colored, 0 and 1 repersent different colors
    vi color(n, -1);
    bool is_bipartite = true;
    qi q;
    
    // perform bfs for all the uncolored nodes
    for(int i = 0; i < n; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0; // default color
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto x: adj[node]) {
                    // if x is un-colored perform bfs on it
                    if (color[x] == -1) {
                        color[x] = color[node] ^ 1;
                        q.push(x);
                    } else {
                        // update is_bipartite if same color as parent
                        is_bipartite = is_bipartite & color[x] != color[node]; 
                    }
                }
            }
        }
    }

    return is_bipartite;

}


// general function to denote nodes in a graph
// numbered from 0
// and get edges from user
int main() {
    int n;
    int node1, node2;
    cin >> n;
    vector < vector <int> > edges;
    for (int i = 0; i < n; i++) {
        cin >> node1 >> node2;
        edges.push_back(vector <int> {node1, node2});
    }

    // abstract function to check if graph is bi-partite
    
}