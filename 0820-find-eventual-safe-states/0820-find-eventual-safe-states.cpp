class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);   // reversed graph
        vector<int> indegree(n, 0);        // indegree in reversed graph

        // Step 1: Reverse the graph and calculate indegree
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        // Step 2: Push terminal nodes (indegree 0 in original graph) into queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Do BFS (topo sort) on reversed graph
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Sort result
        sort(safe.begin(), safe.end());
        return safe;
    }
};
