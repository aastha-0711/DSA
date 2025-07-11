class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prevRow(n, 0);

        prevRow[0] = grid[0][0];

        // Fill the first row
        for (int j = 1; j < n; j++) {
            prevRow[j] = prevRow[j - 1] + grid[0][j];
        }

        // Process each row
        for (int i = 1; i < m; i++) {
            vector<int> currRow(n, 0);
            currRow[0] = prevRow[0] + grid[i][0]; // First column

            for (int j = 1; j < n; j++) {  // Fixed here!
                int fromTop = prevRow[j];
                int fromLeft = currRow[j - 1];
                currRow[j] = grid[i][j] + min(fromTop, fromLeft);
            }

            prevRow = currRow;
        }

        return prevRow[n - 1];
    }
};
