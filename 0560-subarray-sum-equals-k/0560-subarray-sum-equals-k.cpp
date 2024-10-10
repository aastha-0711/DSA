class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;  // Reset sum for each new subarray starting at index i
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];  // Add current element to sum
                if (sum == k) {
                    count++;  // If subarray sum equals k, increment count
                }
            }
        }
        return count;
    }
};
