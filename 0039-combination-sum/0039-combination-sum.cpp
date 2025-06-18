class Solution {
private:
    void backtrack(vector<int>& candidates, int target, vector<int>& combination,
                   vector<vector<int>>& result, int index) {
        if (index == candidates.size()) {
            if(target==0){
                result.push_back(combination);
            }
            return;
        }
        if(candidates[index]<=target){
            combination.push_back(candidates[index]);
                    backtrack(candidates, target-candidates[index], combination, result, index);
                    combination.pop_back();

        }
                    backtrack(candidates, target, combination, result, index+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, combination, result, 0);
        return result;
    }
};

