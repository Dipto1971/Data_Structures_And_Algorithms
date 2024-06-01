#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<int> dijkstra(vector<int> graph[], int V, int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;
	vector <bool> visited(V, false);

	for(int count=0; count< V-1; count++){
		int u = -1;
		for(int i=0; i<V; i++){
			if(!visited[i] && (u == -1 || dist[i] < dist[u])){
				u = i;
			}
		}

		visited[u] = true;
		for(int v=0; v<V; v++){
			if(!visited[v] && graph[u][v] != 0){
				dist[v] = min(dist[v], dist[u] + graph[u][v]);
			}
		}
	}
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<int> graph[V];
	for(int i=0; i<E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	vector<int> dist = dijkstra(graph, V, 0);
	for(int i=0; i<V; i++){
		cout << dist[i] << " ";
	}
	return 0;
}