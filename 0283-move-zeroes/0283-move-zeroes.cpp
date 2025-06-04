class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;  // start empty

        // Add all non-zero elements
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
        }

        // Add zeros for the remaining size
        int zeros = nums.size() - ans.size();
        for(int i = 0; i < zeros; i++){
            ans.push_back(0);
        }

        // Copy back to original nums
        for(int i = 0; i < nums.size(); i++){
            nums[i] = ans[i];
        }
    }
};
