class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
      vector<int> ans(n+1,0);
      for(int i=0;i<n;i++){
ans[nums[i]]=-1;
      }
      int req;
      for(int i=0;i<ans.size();i++){
        if(ans[i]==0){
            req= i;
        }
      } return req;  
    }
};