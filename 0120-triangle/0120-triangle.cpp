class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n - 1]); // Start with the last row

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Choose the min of the two paths from the row below
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};