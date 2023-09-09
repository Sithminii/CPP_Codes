//Minimum Spaning Tree

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph representation as an adjacency list
vector<vector<pair<int, int>>> graph;

// Function to add an edge to the graph
void addEdge(int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Function to find the MST using Prim's algorithm
vector<pair<pair<int, int>, int>> primMST(int numNodes) {
    // Initialize data structures
    vector<int> key(numNodes, INT_MAX);
    vector<int> parent(numNodes, -1);
    vector<bool> inMST(numNodes, false);

    // Priority queue to store nodes and their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with Node 0
    int startNode = 0;
    pq.push(make_pair(0, startNode));
    key[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        // Iterate through adjacent nodes of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not yet included in MST and weight of (u,v) is smaller than key[v]
            if (!inMST[v] && weight < key[v]) {
                // Update key value and parent of v
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Create a vector to store MST edges and their weights
    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i = 1; i < numNodes; ++i) {
        int u = parent[i];
        int v = i;
        int weight = key[i];
        mstEdges.push_back(make_pair(make_pair(u, v), weight));
    }

    return mstEdges;
}

int main() {
    int numNodes = 6;
    graph.resize(numNodes);

    // Add edges to the graph
    addEdge(0, 1, 3);
    addEdge(0, 5, 1);
    addEdge(1, 2, 2);
    addEdge(1, 3, 1);
    addEdge(1, 4, 10);
    addEdge(2, 3, 3);
    addEdge(2, 5, 5);
    addEdge(3, 4, 5);
    addEdge(4, 5, 4);

    // Find the MST
    vector<pair<pair<int, int>, int>> mstEdges = primMST(numNodes);

    // Display the MST edges and their weights
    cout << " Edge   : Weight:" << endl;
    for (const auto& edge : mstEdges) {
        cout << edge.first.first << " - " << edge.first.second << "\t:  " << edge.second << endl;
    }

    return 0;
}
