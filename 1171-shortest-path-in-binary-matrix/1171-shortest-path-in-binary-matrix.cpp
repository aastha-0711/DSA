class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // If starting or ending cell is blocked, return -1
        if (grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        grid[0][0] = 1;  // Mark the starting point as visited with a distance of 1
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int pathlen = grid[x][y];
            
            // If we reach the bottom-right corner, return the path length
            if (x == m-1 && y == n-1) {
                return pathlen;
            }

            // Explore all 8 possible directions
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                // Check boundaries and if the cell is unvisited (i.e., equals 0)
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 0) {
                    q.push({newX, newY});
                    grid[newX][newY] = pathlen + 1;  // Mark it with the path length
                }
            }
        }

        // If no path is found, return -1
        return -1;
    }
};
