#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define vvi vector <vi>
#define si stack <int>
#define qi queue <int>
#define space " "
#define tab "\t"
#define newLine "\n"

bool isDfsCycle(vvi &adj, vi &vis, int i, int pre) {
    vis[i] = 1;
    for(auto x: adj[i]) {
        if (!vis[x] && isDfsCycle(adj, vis, x, i)) {
            return true;
        } else {
            if (x != pre) {
                return true;
            }
        }
    }
    return false;
}

// abstract function for checking cycle
bool isCycle(int n, vvi &adj) {
    vi vis(n, 0);

    for(int i = 0; i < n; i++) {
        if (!vis[i] && isDfsCycle(adj, vis, i, -1)) {
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