class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        } priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            minh.push({i->second,i->first});
            if(minh.size()>k)
            {
                minh.pop();
            }
        }
    vector<int> result;
        while(minh.size()>0)
        {
            result.push_back(minh.top().second);
            minh.pop();
        }
    return result;}
    
};