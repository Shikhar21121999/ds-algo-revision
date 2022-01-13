#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>

// we store a directed graph as a vvi
// using adjacency list representation

int main() {
	int n;
    int edge;
    cin >> n >> edge;

    vvi adj(n);

    // edge is represented as two numbers p,q
    // where edge is from p -> q
    int p,q;
    for (int i=0; i<edge; i++) {
        cin >> p >> q;
        adj[p].push_back(q);
    }
}