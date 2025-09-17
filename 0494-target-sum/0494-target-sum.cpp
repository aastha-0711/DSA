class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
          int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((target + sum) % 2 != 0 || abs(target) > sum)
            return 0;
             int a = (target + sum) / 2;
             vector<vector<int>> dp(n, vector<int>(a + 1, 0));
             dp[0][0] = 1;
             if (nums[0] <= a) dp[0][nums[0]] += 1;
              for (int i = 1; i < n; i++) {
            for (int j = 0; j <= a; j++) {
                dp[i][j] += dp[i - 1][j];  // not take current
                if (j - nums[i] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i]];  // take current
            }
        }

        return dp[n - 1][a];
    }
};
