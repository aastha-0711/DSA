class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, we cannot divide it into 2 equal subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        // dp[i][j] = true if we can form sum j using first i elements
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Sum 0 is always possible (by taking nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Build the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    // Take or don't take the current number
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    // Cannot take the number
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
