class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=0;
        int prev=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                n++;
            }
            else{
                prev=max(n,prev);
                n=0;
            }
            
        }
        return max(n,prev);
    }
};