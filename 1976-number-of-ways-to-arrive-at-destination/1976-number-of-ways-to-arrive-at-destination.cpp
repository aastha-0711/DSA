
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Build the graph using an adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time); // Because the roads are bi-directional
        }

        // Step 2: Initialize distances and ways
        vector<long long> dist(n, LLONG_MAX); // Use long long for distances
        vector<int> ways(n, 0);
        dist[0] = 0; // Distance to the starting intersection is 0
        ways[0] = 1; // There's one way to be at the starting point

        // Step 3: Use a priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // Use long long for distances
        pq.push({0, 0}); // (distance, intersection)

        // Step 4: Dijkstra's algorithm
        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            // If we find a longer distance, we skip it
            if (currentDist > dist[currentNode]) {
                continue;
            }

            // Explore neighbors
            for (const auto& neighbor : graph[currentNode]) {
                int neighborNode = neighbor.first;
                int travelTime = neighbor.second;

                // Calculate new distance safely
                long long newDist = static_cast<long long>(currentDist) + travelTime;

                // If we found a shorter way to reach neighborNode
                if (newDist < dist[neighborNode]) {
                    dist[neighborNode] = newDist;
                    ways[neighborNode] = ways[currentNode]; // Update the number of ways
                    pq.push({newDist, neighborNode});
                } else if (newDist == dist[neighborNode]) {
                    // If we found another shortest path to neighborNode
                    ways[neighborNode] = (ways[neighborNode] + ways[currentNode]) % MOD;
                }
            }
        }

        // Step 5: Return the number of ways to reach the last intersection
        return ways[n - 1]; // Ways to reach intersection n-1
    }
};
