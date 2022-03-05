#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>
#define pii pair <int, int>
#define vpii vector <pii>
#define vvpii vector <vpii>

vector <int> allPairShortestPath(int src, int nodes, vvi &edges) {

    // create a graph
    vvpii adj(nodes+1);

    for (auto edge: edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    // create a shortest distance array
    vi sDist (nodes+1, INT_MAX);
    vi parent (nodes+1, -1);  // to store parent of each node in the shortest path

    // create a min heap priority queue
    priority_queue <pii, vpii, greater <int>> mpq;

    sDist[src] = 0;
    mpq.push({0, src}); // distance, node

    while (!mpq.empty()) {
        int dist = mpq.top().first;
        int prev = mpq.top().second;
        mpq.pop();

        // relax all the possible edges through this node
        for (auto x: adj[prev]) {
            int nxt = x.first;
            int wt = x.second;
            if (sDist[nxt] > sDist[prev] + wt) {
                sDist[nxt] = sDist[prev] + wt;
                parent[nxt] = prev;
                mpq.push({sDist[nxt], nxt});
            }
        }
    }

    // can send back parent to construct the path

    return sDist;
}

int main () {
    // number of nodes labelled from 1
    int n;
    cin >> n;

    int edgeCnt;
    cin >> edgeCnt;

    vector < vector <int> > edges;
    for (int i = 0; i < edgeCnt; i++) {
        int n1, n2, wt;
        cin >> n1 >> n2 >> wt;
        edges.push_back({n1, n2, wt});
    }

    int src;
    cin >> src;

    vi distances = allPairShortestPath(src, n, edges);
}