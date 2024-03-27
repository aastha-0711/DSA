class Solution {
public:
    int singleNumber(vector<int>& nums){
        //USING MAPS
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // int ans;
        // for(auto x:mp){
        //     if(x.second==1){
        //         ans=x.first;
        //     }
        // }
        // return ans;
        
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};