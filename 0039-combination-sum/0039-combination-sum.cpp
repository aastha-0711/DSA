class Solution {
private:
    void backtrack(vector<int>& candidates, int target, vector<int>& combination,
                   vector<vector<int>>& result, int index) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                // We pass 'i' again because we can reuse same element
                backtrack(candidates, target - candidates[i], combination, result, i);
                combination.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, combination, result, 0);
        return result;
    }
};
