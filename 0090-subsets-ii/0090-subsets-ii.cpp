class Solution {
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates on the same level
            if (i > index && nums[i] == nums[i - 1]) continue;

            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Important to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};
