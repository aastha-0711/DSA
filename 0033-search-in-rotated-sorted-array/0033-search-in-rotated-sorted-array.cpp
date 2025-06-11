class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }

            // this part checks if left side is sorted then: not caring about right side
            if(nums[start]<=nums[mid]){
                if(target>=nums[start] && target<nums[mid]){
end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            // this part assumens that right side is orted not caring about left side
            else if(nums[mid]<=nums[end]){
                if(target<=nums[end] && nums[mid]<target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;

    }
};