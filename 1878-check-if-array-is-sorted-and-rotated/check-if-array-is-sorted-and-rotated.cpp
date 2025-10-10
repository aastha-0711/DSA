class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        int vec = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                vec++;
            }
        }

        if (vec >1 ) {
            return false;
        }
        return true;
    }
};
