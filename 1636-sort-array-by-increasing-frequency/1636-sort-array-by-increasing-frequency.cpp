class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>> maxh;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            maxh.push({it->second, it->first});
        }

        vector<int> result;
        while (!maxh.empty()) {
            int freq = maxh.top().first;
            int element = maxh.top().second;
            maxh.pop();
            for (int i = 0; i < freq; i++) {
                result.push_back(element);
            }
        }
        
        // Sort elements with the same frequency based on their values
        sort(result.begin(), result.end(), [&](int a, int b) {
            if (mp[a] == mp[b]) {
                return a > b; // If frequency is same, sort based on values in descending order
            }
            return mp[a] < mp[b]; // Otherwise, sort based on frequency in ascending order
        });

        return result;
    }
};