class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();              // Number of cities
        vector<bool> visited(n, false);          // To track visited cities
        int provinceCount = 0;                   // To count provinces
        
        // Iterate over each city
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {                   // If the city is not visited
                stack<int> stack;                // Stack for DFS
                stack.push(i);                   // Push the current city to start DFS
                
                // Perform DFS
                while (!stack.empty()) {
                    int city = stack.top();      // Get the current city
                    stack.pop();
                    
                    if (!visited[city]) {        // Mark the current city as visited
                        visited[city] = true;

                        // Check all cities connected to the current city
                        for (int j = 0; j < n; ++j) {
                            if (isConnected[city][j] == 1 && !visited[j]) {
                                stack.push(j);   // If a connected city is unvisited, push it to the stack
                            }
                        }
                    }
                }

                // After a full DFS traversal, one province has been found
                provinceCount++;
            }
        }

        return provinceCount;                    // Return the total number of provinces
    }
};
