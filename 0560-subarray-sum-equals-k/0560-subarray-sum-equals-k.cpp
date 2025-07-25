
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1; // to handle subarrays that sum to k from index 0
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - k;
            if(mp.find(rem) != mp.end()) {
                count += mp[rem]; // add all occurrences of rem
            }
            mp[sum]++; // store the frequency of this prefix sum
        }
        return count;
    }
};
