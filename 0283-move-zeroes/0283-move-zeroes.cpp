class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;  // where to place the next non-zero

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }

        // Fill remaining positions with zeros
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    }
};
