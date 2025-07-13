class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: no valid partition
        if ((target + sum) % 2 != 0 || abs(target) > sum)
            return 0;

        int a = (target + sum) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(a + 1, 0));
        dp[0][0] = 1; // base case: 1 way to get sum 0 using 0 elements

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= a; j++) {
                // Don't pick current number
                dp[i][j] = dp[i - 1][j];

                // Pick current number (nums[i-1]) if j is big enough
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][a];
    }
};
