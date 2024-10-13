class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==target){
                return true;
            }
            else{
                i++;
            }
        }return false;
    }
};