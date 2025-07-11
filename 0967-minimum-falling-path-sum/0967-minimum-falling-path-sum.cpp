class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(matrix[n - 1]);  // Start with the last row

        for (int i = n - 2; i >= 0; i--) {
            vector<int> newDp(n, 0);
            for (int j = 0; j < n; j++) {
                int down = dp[j];
                int leftDiag = (j > 0) ? dp[j - 1] : INT_MAX;
                int rightDiag = (j < n - 1) ? dp[j + 1] : INT_MAX;
                newDp[j] = matrix[i][j] + min({down, leftDiag, rightDiag});
            }
            dp = newDp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
