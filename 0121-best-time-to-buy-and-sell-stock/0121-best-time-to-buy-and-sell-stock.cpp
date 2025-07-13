class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> dp(n, 0);  // dp[i] = max profit until day i
        int min_price = prices[0];

        for (int i = 1; i < n; i++) {
            min_price = min(min_price, prices[i]);  // keep track of min so far
            dp[i] = max(dp[i - 1], prices[i] - min_price);  // max of not selling or selling today
        }

        return dp[n - 1];  // max profit overall
    }
};
