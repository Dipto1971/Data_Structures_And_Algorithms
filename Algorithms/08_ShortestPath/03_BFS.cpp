#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

void BFS(vector<int> adj[], int V, int src, bool visited[]){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void BFSDis (vector<int> adj[], int V){
    bool visited[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            BFS(adj, V, i, visited);
        }
    }
}

