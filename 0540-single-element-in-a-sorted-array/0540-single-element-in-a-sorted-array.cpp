class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // Count the occurrences of each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        // Find the number that occurs only once
        for (auto& it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        
        return -1; // In case no element is found (though input guarantees a single element)
    }
};
