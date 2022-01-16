#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define vvi vector <vi>
#define si stack <int>
#define qi queue <int>
#define space " "
#define tab "\t"
#define newLine "\n"

bool isBfsCycle(vvi &adj, vi &vis, int i, int n) {
    queue < pair <int, int> > q;
    q.push({i, -1}); // first node has no parent

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        // perform bfs
        for (auto x: adj[curr.first]) {
            if(!vis[curr.first]) {
                vis[curr.first] = true;
                q.push({x, curr.first});
            } else {
                if (x != curr.first) {
                    return true;
                }
            }
        }
    }
    return false;
}

// abstract function for checking cycle
bool isCycle(int n, vvi &adj) {
    vi vis(n, 0);

    for(int i = 0; i < n; i++) {
        if (!vis[i] && isBfsCycle(adj, vis, i, n)) {
            return true;
        } 
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vvi adj(n);

    int edges;
    cin >> edges;
    int n1, n2;
    for (int i = 0; i < edges; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}