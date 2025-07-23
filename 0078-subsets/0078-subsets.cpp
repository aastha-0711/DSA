class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int totalSubsets = 1 << n;  // 2^n

        for (int i = 0; i < totalSubsets; i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                // Check if j-th bit is set in i
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};
