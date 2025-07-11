class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;  // A large number representing impossible

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        // Base case: 0 coins to make amount 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
         for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    // Take the coin or don't take it
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                } else {
                    // Can't take the coin
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
    }
};    