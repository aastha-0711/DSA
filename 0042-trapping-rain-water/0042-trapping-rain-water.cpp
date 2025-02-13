class Solution {
public:
    int trap(vector<int>& height) {
        int right_max=height[height.size()-1];
        int left_max=height[0];
int left=0;
int water=0;
int right=height.size()-1;
while(left<right){
    if(left_max<right_max){
left++;
left_max=max(left_max, height[left]);
    water+=left_max-height[left];

}
else{
    right--;
    right_max=max(right_max,height[right]);
    water+=right_max-height[right];
}
    
}
return water;
    }
};