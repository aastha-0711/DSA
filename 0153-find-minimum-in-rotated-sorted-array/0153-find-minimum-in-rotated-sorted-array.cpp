class Solution {
public:
    int findMin(vector<int>& nums) {
        int ind=0;
   for(int i=nums.size()-2;i>=0;i--){
    if(nums[i]>nums[i+1]){
ind=i+1;
    }
   }
   return nums[ind];     
    }
};