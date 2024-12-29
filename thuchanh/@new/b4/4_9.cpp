#include <iostream>
#include <queue>
#include <climits>
#include <vector>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adj) {
    // priority queue stores pairs (distance from 0, vertex)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> Q;

    std::vector<int> d(adj.size(), INT_MAX);
    d[0] = 0; // start from vertex 0
    Q.push({0, 0}); // push the start node with distance 0

    while (!Q.empty()) {
        int du = Q.top().first;  // current distance
        int u = Q.top().second;   // current node
        Q.pop();

        // If this distance is not up-to-date, skip
        if (du != d[u]) continue;

        // Explore neighbors
        for (auto e : adj[u]) {
            int v = e.first;  // neighbor vertex
            int c = e.second; // edge cost

            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;  // update distance
                Q.push({d[v], v}); // push to priority queue
            }
        }
    }

    return d;
}

int main() {
    int n = 9; // Number of vertices
    std::vector<std::vector<std::pair<int, int>>> adj(n);

    // Function to add edges
    auto add_edge = [&adj](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming undirected graph
    };

    // Add edges
    add_edge(0, 1, 4);
    add_edge(1, 7, 11);
    add_edge(0, 7, 8);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    // Run Dijkstra algorithm
    std::vector<int> distance = dijkstra(adj);

    // Output the distances
    for (int i = 0; i < distance.size(); ++i) {
        std::cout << "distance 0->" << i << " = " << distance[i] << std::endl;
    }

    return 0;
}
