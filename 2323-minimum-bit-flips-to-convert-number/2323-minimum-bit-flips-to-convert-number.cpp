class Solution {
public:
    int minBitFlips(int start, int goal) {
       int number=start^goal;
       int count=0;
       while(number>0){
number=number&(number-1);
count++;
       } 
       return count;
    }
};