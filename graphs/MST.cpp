#include <bits/stdc++.h>
using namespace std;

// program to find Minimum Spanning Tree using Kruskal's Algorithm
// DSU implementation

/*
refer to https://www.interviewbit.com/problems/commutable-islands/
for imputs to MST
*/

int findSet (int a, vector <int> &parent) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = findSet(parent[a], parent);
}

int unionSet (int a, int b, vector <int> &parent, vector <int> &sizes) {
    a = findSet(a, parent);
    b = findSet(b, parent);

    if (a!=b) {
        // they belong to different sets hence we merge the smaller
        // set to bigger set
        if (sizes[a] < sizes[b]) swap(a,b);
        parent[b] = a;
        // increment the size of set
        sizes[a] += sizes[b];
        return 1;
    }
    return 0;
}

bool compare (vector <int> a1, vector <int> a2) {
    return a1[2] < a2[2];
}

// function to find MST
int MST(int n, vector <vector <int>> edges) {
    // sort the edges according to weight
    sort(edges.begin(), edges.end(), compare);

    // initialize a dsu for n nodes
    vector <int> parent(n+1);
    vector <int> size(n+1, 0);

    // each element is the parent of itself
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int uParent = findSet(edges[i][0], parent);
        int vParent = findSet(edges[i][1], parent);

        if (uParent != vParent) {
            unionSet(edges[i][0], edges[i][1], parent, size);
            ans += edges[i][2];
        }
    }
    return ans;

}

int main () {

}