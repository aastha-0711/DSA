class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int posIndex = 0, negIndex = 1;
        for(int num:nums){
            if(num>0){
                res[posIndex]=num;
                posIndex+=2;
            }
            else{
                res[negIndex]=num;
                negIndex+=2;
            }
        }return res;
    }
        
};