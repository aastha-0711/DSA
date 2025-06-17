class Solution {
    private:
    void subsets(vector<int>& nums, int i, vector<int>& current, vector<vector<int>>& ans){
        ans.push_back(current);
        for(int j=i;j<nums.size();j++){
            current.push_back(nums[j]);
            subsets(nums,j+1,current,ans);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
        vector<int> current;
        subsets(nums,0,current,ans);
        return ans;
    }
};