class Solution {
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& memo) {
        if (amount == 0) return 1;              // found valid combination
        if (i == coins.size() || amount < 0) return 0; // out of bounds or too much

        if (memo[i][amount] != -1) return memo[i][amount];

        // Choices:
        int take = solve(i, amount - coins[i], coins, memo);     // take coin[i]
        int skip = solve(i + 1, amount, coins, memo);             // skip coin[i]

        return memo[i][amount] = take + skip;}
public:
   int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, memo);
    }
};