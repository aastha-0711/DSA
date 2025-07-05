class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        // Step 1: Push all boundary land cells into queue
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if (grid[i][n-1] == 1) {
                q.push({i, n-1});
                grid[i][n-1] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if (grid[m-1][j] == 1) {
                q.push({m-1, j});
                grid[m-1][j] = 0;
            }
        }

        // Step 2: BFS flood-fill to mark all land connected to boundary
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int xx = x + dx;
                int yy = y + dy;

                if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 1) {
                    q.push({xx, yy});
                    grid[xx][yy] = 0;
                }
            }
        }

        // Step 3: Count remaining land cells (not connected to boundary)
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};
