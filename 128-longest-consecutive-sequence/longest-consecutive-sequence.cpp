class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){return 0;}
        unordered_set myset(nums.begin(),nums.end());
        int longest=1;
        for(int num:myset){
        if(myset.find(num-1)==myset.end()){
int currentNum= num;
int currentStreak=1;
        
        while(myset.find(currentNum+1)!=myset.end()){
            currentStreak++;
            currentNum++;
        }
longest=max(longest,currentStreak);}
    }return longest;}
};