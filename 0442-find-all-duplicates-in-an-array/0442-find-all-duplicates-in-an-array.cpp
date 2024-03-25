class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int m=nums.size();
     vector<int> findDuplicates1;
        for(int i=0;i<m;i++)
        {
            if(nums[(abs(nums[i])-1)]<0)
            {
                findDuplicates1.push_back(abs(nums[i]));
            }
                else 
                    nums[(abs(nums[i])-1)]=-nums[(abs(nums[i])-1)];
        }
            
            return findDuplicates1;
    }
};