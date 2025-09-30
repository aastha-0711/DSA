class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 1) return 1;

        // dp[i] will store number of ways to reach step i
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // 1 way to stay at the ground
        dp[1] = 1;  // 1 way to reach first step

        // Fill dp array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
