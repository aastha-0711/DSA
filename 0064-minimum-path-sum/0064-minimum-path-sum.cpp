class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();       // number of rows
        int n = grid[0].size();    // number of columns

        // dp[i][j] will store the min path sum to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];  // start cell

        // Fill first row (can only come from left)
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill first column (can only come from top)
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // The answer is at the bottom-right corner
        return dp[m - 1][n - 1];
    }
};
