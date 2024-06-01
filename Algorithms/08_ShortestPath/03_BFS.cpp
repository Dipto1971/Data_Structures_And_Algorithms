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

int main(){
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    adj[4].push_back(4);

    cout << "Following is Breadth First Traversal: " << endl;
    BFSDis(adj, V);

    return 0;
}

