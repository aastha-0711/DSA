class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int nei : graph[node]) {
            if (!visited[nei]) dfs(nei, graph, visited);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int components = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                components++;
            }
        }

        return n - components;
    }
};
