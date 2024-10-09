class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        vector<int> nums2(n);  
        for (int i = 0; i < n; i++) {
            nums2[(i + k) % n] = nums[i];  // Correct indexing for rotation
        }

        // Copy rotated elements back to original array
        nums = nums2;
    }
};
