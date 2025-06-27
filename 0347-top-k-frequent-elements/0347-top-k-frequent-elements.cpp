class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int> freq ;
        vector<int> ans;
        for(int i:nums) freq[i]++;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
         for(int i=0;i<k;i++) pq.push({0,-1});
          for(auto it : freq){
            int f = it.second;
            int num = it.first;
           if(f>pq.top().first) {
                pq.pop();
                pq.push({f,num});
            }}
             while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
          }
      return ans;
    }
};