class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                k--;  // Use a flip
            }

            while (k < 0) {
                // Shrink from left until we can afford a new 0
                if (nums[left] == 0) {
                    k++;  // Reclaim a flip
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
