#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breakCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                breakCount++;
                // More than one break point, array can't be sorted by a single rotation
                if (breakCount > 1) {
                    return false;
                }
            }
        }
        
        // If we have zero or one break point, it means the array is a rotated sorted array
        return true;
    }
};
