class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
        vector<vector<int>> reverseGraph(n); // To store the reverse graph
        vector<int> inDegree(n, 0);          // To store the in-degree of nodes in the reverse graph

        // Step 1: Build the reverse graph and compute in-degrees
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);  // Reverse the edge i -> neighbor to neighbor -> i
                inDegree[i]++;  // Increment the in-degree of node i
            }
        }

        // Step 2: Initialize a queue with all nodes having in-degree 0 (terminal nodes in the original graph)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process the nodes using BFS
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);  // This node is safe

            // For each node that points to 'node' in the reverse graph, decrease its in-degree
            for (int neighbor : reverseGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);  // If in-degree becomes 0, it's a safe node
                }
            }
        }

        // Step 4: Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};  
