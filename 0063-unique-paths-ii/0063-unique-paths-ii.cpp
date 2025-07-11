class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> aboveRow(n, 0);

        // Initialize the first row
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            aboveRow[j] = 1;
        }

        for (int i = 1; i < m; i++) {
            vector<int> currentRow(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    currentRow[j] = 0;
                } else {int fromTop = aboveRow[j];
                    int fromLeft = (j > 0) ? currentRow[j - 1] : 0;
                    currentRow[j] = fromTop + fromLeft;
                }
            }
            aboveRow = currentRow;
        }
return obstacleGrid[m - 1][n - 1] == 1 ? 0 : aboveRow[n - 1];
    }
};