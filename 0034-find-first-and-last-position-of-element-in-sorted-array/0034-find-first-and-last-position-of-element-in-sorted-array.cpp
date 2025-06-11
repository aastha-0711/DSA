class Solution {
private:
    int firstOccurrence(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int ind = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ind = mid;
                end = mid - 1; // go left to find first occurrence
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ind;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int ind = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ind = mid;
                start = mid + 1; // go right to find last occurrence
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ind;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurrence(nums, target), lastOccurrence(nums, target)};
    }
};
