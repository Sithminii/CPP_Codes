//SSSP using Dijkstra’s Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<vector<int>>& graph, int source, vector<int>& distances) {
    int n = graph.size();
    distances.resize(n, INT_MAX); // Initialize distances as infinity
    distances[source] = 0; // Distance from source to itself

    // Create a min-heap priority queue to store vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source)); // Push source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the minimum distance
        pq.pop();

        // Visit all neighbors of vertex u
        for (int v = 0; v < n; v++) {
            // If there is an edge between u and v
            if (graph[u][v] > 0) {
                int weight = graph[u][v]; // Weight of the edge (u, v)

                // If the distance to v through u is shorter, update the distance
                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.push(make_pair(distances[v], v)); // Push updated distance and vertex into the priority queue
                }
            }
        }
    }
}

int main() {
    // Define the adjacency matrix for the graph
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int n = graph.size(); // Number of vertices

    int source; // Source vertex
    cout<<"Source city : ";
    cin >> source;

    vector<int> distances; // Vector to store the shortest distances
    dijkstra(graph, source, distances);

    // Print the shortest distances from the source
    for (int i = 0; i < n; i++) {
        if (i==source) {
            continue;
        }
        else {
            cout << "Shortest distance from " << source << " to " << i << " is " << distances[i] << endl;
        }
    }

    return 0;
}
