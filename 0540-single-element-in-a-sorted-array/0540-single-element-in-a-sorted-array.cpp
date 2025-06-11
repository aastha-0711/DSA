class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     int end=nums.size()-1;
     if(nums.size()==1){return nums[0];}
     if(nums[0]!=nums[1])return nums[0];
     if(nums[end]!=nums[end-1])return nums[end];
     int low=1;
     int high=end-1; 
      while(low<=high){
        int mid=low+(high-low)/2;
if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
    return nums[mid];
}
if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
    low=mid+1;

}
else{

    high=mid-1;
}
      }return -1;
    }
};