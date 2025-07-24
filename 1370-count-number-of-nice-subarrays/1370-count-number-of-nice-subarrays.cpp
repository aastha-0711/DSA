class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, count = 0, left = 0;
for (int r = 0; r < nums.size(); r++) {
    if (nums[r] % 2) {
        k--;
        count=0; // each odd reduces k
    }
    while (k == 0) {  // valid window with exactly k odds
        count++;              // count valid subarrays ending at r
        k += (nums[left++] % 2);  // shrink window from left
    }

    res += count;  // add all valid subarrays ending at r
}
return res;
    }
};
