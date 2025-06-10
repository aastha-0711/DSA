class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]){
continue;
        }
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
int sum=nums[i]+nums[j]+nums[k];
if(sum<0){
    j++;
}
else if(sum>0){
    k--;
}
else{
    ans.push_back({nums[i],nums[j],nums[k]});
    j++;
    while(j<k && nums[j-1]==nums[j]){
        j++;
    }
}

        }}return ans;
    }
};