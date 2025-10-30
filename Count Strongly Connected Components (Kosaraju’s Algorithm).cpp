#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis,
         stack<int> &st, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void reversedfs(int node, unordered_map<int, bool> &vis,
                unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            reversedfs(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int nodeV = edges[i][1];
        adj[u].push_back(nodeV);
    }

    // Step 2: Topological sort using DFS
    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Step 3: Transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        vis[i] = false; // reset visited
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 4: Do DFS on the transposed graph in stack order
    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!vis[top]) {
            count++;
            reversedfs(top, vis, transpose);
        }
    }

    return count;
}
