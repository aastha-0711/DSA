class Solution {
private:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result,
                   vector<int>& temp, int index) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (candidates[i] > target) break; // pruning

            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, temp, i + 1); // i+1 since each number used once
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, result, temp, 0);
        return result;
    }
};
