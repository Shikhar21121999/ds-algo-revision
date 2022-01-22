#include<bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>
# define pii pair <int, int>
# define vpii vector <pii>
# define vvpii vector <vpii>
# define si stack <int>

/*
Algorithm is to first find topoSort of the graph
then for each node in the topoSort order use bfs
to relax edges and store shortest distance array
*/

// function to find topoSort

void topoSort(vvpii &graph, int node, vi &vis, stack <int> &topoOrder) {
    vis[node] = 1;
    for (auto x: graph[node]) {
        if (!vis[x.first]) {
            topoSort(graph, x.first, vis, topoOrder);
        }
    }
    topoOrder.push(node);
}

vi shortestPathDAG(vvpii &graph, int src, int n) {
    vi vis(n, 0);
    stack <int> topoOrder;
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topoSort(graph, i, vis, topoOrder);
        }
    }

    // find shortest distance using nodes in the topotOrder
    vi sd(n,INT_MAX);

    while(!topoOrder.empty()) {
        int node = topoOrder.top();
        topoOrder.pop();

        if (sd[node] != INT_MAX) {
            for (auto x: graph[node]) {
                int v = x.first;
                int wt = x.second;

                if (sd[v] > sd[node] + wt) {
                    sd[v] = sd[node] + wt;
                }
            }
        }
    }
    return sd;
}

int main () {
    // number of nodes
    // nodes are numbered from 0
    int n;
    cin >> n;

    int edges;
    cin >> edges;

    int n1,n2,w;
    vvpii graph(n);

    while(edges--) {
        cin >> n1 >> n2 >> w;
        graph[n1].push_back(make_pair(n2, w));
    }

    int src;
    cin >> src;

    vi sd = shortestPathDAG(graph, src, n);

    for (int i = 0; i < n; i++) {
        cout << i << " " << sd[i] << "\n";
    }
}