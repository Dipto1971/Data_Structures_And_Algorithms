#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Function to find the vertex with minimum distance
int minDistance(vector<int> dist, vector<bool> visited) {
    int minimum = INF, minVertex = 0;
    for (int vertex = 0; vertex < dist.size(); vertex++) {
        if (minimum > dist[vertex] && visited[vertex] == false) {
            minimum = dist[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}

// Dijkstra Algorithm for Modified Graph
void Dijkstra(vector<vector<int>> graph, vector<vector<int>> modifiedGraph, int src) {
    int num_vertices = graph.size();
    vector<bool> sptSet(num_vertices, false);
    vector<int> dist(num_vertices, INF);

    dist[src] = 0;

    for (int count = 0; count < num_vertices; count++) {
        int curVertex = minDistance(dist, sptSet);
        sptSet[curVertex] = true;

        for (int vertex = 0; vertex < num_vertices; vertex++) {
            if (!sptSet[vertex] && graph[curVertex][vertex] != 0 &&
                dist[curVertex] != INF && 
                dist[vertex] > (dist[curVertex] + modifiedGraph[curVertex][vertex])) {
                dist[vertex] = dist[curVertex] + modifiedGraph[curVertex][vertex];
            }
        }
    }

    // Print the Shortest distance from the source
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        cout << "Vertex " << vertex << ": " << (dist[vertex] == INF ? "INF" : to_string(dist[vertex])) << endl;
    }
}

// Function to calculate shortest distances from source to all other vertices using Bellman-Ford algorithm
vector<int> BellmanFord(vector<tuple<int, int, int>> edges, int num_vertices) {
    vector<int> dist(num_vertices + 1, INF);
    dist[num_vertices] = 0;

    for (int i = 0; i < num_vertices; i++) {
        edges.push_back(make_tuple(num_vertices, i, 0));
    }

    for (int i = 0; i < num_vertices; i++) {
        for (auto edge : edges) {
            int src, des, weight;
            tie(src, des, weight) = edge;
            if (dist[src] != INF && dist[src] + weight < dist[des]) {
                dist[des] = dist[src] + weight;
            }
        }
    }

    // Don't send the value for the source added
    return vector<int>(dist.begin(), dist.begin() + num_vertices);
}

// Function to implement Johnson Algorithm
void JohnsonAlgorithm(vector<vector<int>> graph) {
    vector<tuple<int, int, int>> edges;

    // Create a list of edges for Bellman-Ford Algorithm
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                edges.push_back(make_tuple(i, j, graph[i][j]));
                // this consists of the edge from i to j with weight graph[i][j]
            }
        }
    }

    // Weights used to modify the original weights
    vector<int> modifyWeights = BellmanFord(edges, graph.size());

    vector<vector<int>> modifiedGraph(graph.size(), vector<int>(graph.size(), INF));

    // Modify the weights to get rid of negative weights
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                modifiedGraph[i][j] = graph[i][j] + modifyWeights[i] - modifyWeights[j];
            }
        }
    }

    cout << "Modified Graph:\n";
    for (auto row : modifiedGraph) {
        for (auto val : row) {
            cout << (val == INF ? "INF" : to_string(val)) << " ";
        }
        cout << endl;
    }

    // Run Dijkstra for every vertex as source one by one
    for (int src = 0; src < graph.size(); src++) {
        cout << "\nShortest Distance with vertex " << src << " as the source:\n";
        Dijkstra(graph, modifiedGraph, src);
    }
}

// Driver Code
int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 7, 0, -2, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, -5, 0}
    };

    JohnsonAlgorithm(graph);
    return 0;
}
