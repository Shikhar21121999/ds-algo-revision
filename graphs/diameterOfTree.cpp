#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define vvi vector <vi>

// Also known as longest path in an undirected tree

/*
Use dfs two times to find the longest path
First dfs determines one of the end point of longest path in the graph
Second dfs counts the length of longest path from this end node
*/

int longestPath(vvi &graphTree) {
    // perform first bfs to get one of the endpoint

    queue <pair <int, int> > q;
    q.push({1, -1});

    int endNode;
    while (!q.empty()) {
        auto nodePair = q.front();
        q.pop();
        endNode = nodePair.first;

        for (auto x: graphTree[nodePair.first]) {
            if (x != nodePair.second) {
                q.push({x, nodePair.first});
            }
        }
    }

    // perform second bfs from endNode
    q.push({endNode, -1});
    int length = -1;
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0 ; i < n; i++) {
            auto nodePair = q.front();
            q.pop();
            endNode = nodePair.first;

            for (auto x: graphTree[nodePair.first]) {
                if (x != nodePair.second) {
                    q.push({x, nodePair.first});
                }
            }
        }
        length++;
    }
    return length;
}

// utility function to perform bfs and return
// a pair of farthest node as well as path length to it
pair <int, int> bfs(vvi &graphTree, int src) {
    queue <pair <int, int> > q;

    q.push({src, -1});
    int length = -1;
    int endNode;

    while(!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto nodePair = q.front();
            q.pop();
            
            endNode = nodePair.first;

            for (auto x: graphTree[nodePair.first]) {
                if (x != nodePair.second) {
                    q.push({x, nodePair.first});
                }
            }
        }
        length++;
    }
    return {endNode, length};
}

int logestPathModular(vvi &graphTree) {
    auto endNode = bfs(graphTree, 0).first;
    return bfs(graphTree, endNode).second;
}

int main () {
    int n;
    cin >> n;

    int edgeCnt;
    cin >> edgeCnt;

    vvi graph(n+1);
    for (int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        // undirected tree
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    cout << longestPath(graph);
}