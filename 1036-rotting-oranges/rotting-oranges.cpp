class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int fresh = 0;

        // Initialize queue with all initially rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges at all
        if (fresh == 0) return 0;

        int minutes = -1;

        // Multi-source BFS
        while (!q.empty()) {
            int sz = q.size();
            minutes++;  // Every level = 1 minute

            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : direction) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // If neighbor is a fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;     // Rot it
                        fresh--;              // One less fresh orange
                        q.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
