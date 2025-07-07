class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [currentEffort, position] = pq.top();
            pq.pop();

            int x = position.first;
            int y = position.second;

            // Early exit: reached bottom-right
            if (x == m - 1 && y == n - 1) {
                return currentEffort;
            }

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
                    int heightDiff = abs(heights[newX][newY] - heights[x][y]);
                    int newEffort = max(currentEffort, heightDiff);

                    if (newEffort < effort[newX][newY]) {
                        effort[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        // Unreachable in practice, because destination is always reachable
        return 0;
    }
};
