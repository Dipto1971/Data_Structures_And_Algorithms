#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

void BFS(vector<int> adj[], int V, int src, bool visited[]){
    // BFS of a connected graph
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
    // BFS of a disconnected graph
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
    // For disconnected graph
    int V = 7;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[5].push_back(6);
    adj[6].push_back(5);

    cout << "Following is Breadth First Traversal: " << endl;
    BFSDis(adj, V);

    // For connected graph
    int V = 4;
    vector<int> adj[V];
    bool visited[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    cout << "Following is Breadth First Traversal: " << endl;
    BFS(adj, V, 0, visited);

    return 0;
}

