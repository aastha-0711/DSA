class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1); // Initialize with -1 (meaning not computed yet)
        return solve(n, dp);
    }

private:
    int solve(int n, vector<int>& dp) {
        if (n <= 1) return n;

        if (dp[n] != -1) return dp[n]; // Already computed

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
};
