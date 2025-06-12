class Solution {
private:
    bool isPossible(vector<int>& nums, int maxSumAllowed, int k) {
        int currentSum = 0;
        int parts = 1;

        for (int num : nums) {
            if (currentSum + num <= maxSumAllowed) {
                currentSum += num;
            } else {
                parts++;
                currentSum = num;
                if (parts > k) return false;
            }
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, mid, k)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
