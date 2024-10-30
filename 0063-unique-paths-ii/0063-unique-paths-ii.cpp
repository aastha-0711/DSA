class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Edge case: If start or end cell is an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;  // Start position

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;  // No paths if there's an obstacle
                } else {
                    // If cell is not at the top row, add paths from the cell above
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    // If cell is not at the left column, add paths from the left cell
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        return dp[m-1][n-1];  // Number of paths to the bottom-right corner
    }
};