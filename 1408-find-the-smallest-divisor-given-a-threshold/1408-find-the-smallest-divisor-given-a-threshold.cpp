class Solution {
private:
    bool div(vector<int>& nums, int threshold, int num) {
        int divv = 0;
        for (int i = 0; i < nums.size(); i++) {
            divv += (nums[i] + num - 1) / num; // integer ceiling
        }
        return divv <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ind = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (div(nums, threshold, mid)) {
                ind = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ind;
    }
};
