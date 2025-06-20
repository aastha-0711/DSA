class Solution {
private:
    void backtrack(vector<int>& candidates, int currentSum, int target,
               vector<int>& combination, vector<vector<int>>& result, int index) {
    if (currentSum == target) {
        result.push_back(combination);
        return;
    }
    if (currentSum > target) return;

    for (int i = index; i < candidates.size(); ++i) {
        combination.push_back(candidates[i]);
        backtrack(candidates, currentSum + candidates[i], target, combination, result, i);
        combination.pop_back();
    }
}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates,0, target, combination, result, 0);
        return result;
    }
};
