#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list to store the flights
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].emplace_back(to, price);
        }
        
        // Priority queue to store (cost, (current_city, stops))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {src, 0}}); // Start from source with 0 cost and 0 stops
        
        // Keep track of the minimum cost to reach each city with stops
        vector<vector<int>> minCost(n, vector<int>(k + 2, numeric_limits<int>::max()));
        minCost[src][0] = 0; // Cost to reach src is 0 with 0 stops
        
        while (!pq.empty()) {
            auto [cost, info] = pq.top();
            pq.pop();
            int current_city = info.first;
            int stops = info.second;

            // If we reached the destination
            if (current_city == dst) {
                return cost;
            }
            
            // If we have made too many stops, continue to next
            if (stops > k) {
                continue;
            }

            // Explore neighbors
            for (const auto& neighbor : graph[current_city]) {
                int next_city = neighbor.first;
                int price = neighbor.second;
                int newCost = cost + price;

                // Only push to priority queue if we find a cheaper way to reach `next_city`
                if (newCost < minCost[next_city][stops + 1]) {
                    minCost[next_city][stops + 1] = newCost;
                    pq.push({newCost, {next_city, stops + 1}});
                }
            }
        }
        
        // If we exit the loop without having found a route to dst, return -1
        return -1;
    }
};
