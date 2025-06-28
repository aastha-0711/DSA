class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i <= count && i < nums.size(); i++) {
            count = max(count, i + nums[i]);
            if (count >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
