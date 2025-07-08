
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        // Step 1: Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Step 2: Floyd-Warshall to compute all-pairs shortest path
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Step 3: Find the city with minimum reachable cities under threshold
        int minReachable = n; // max possible is n-1
        int city = -1;

        for (int i = 0; i < n; i++) {
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }
            // If same count, prefer the city with larger index
            if (reachable <= minReachable) {
                minReachable = reachable;
                city = i;
            }
        }

        return city;
    }
};


