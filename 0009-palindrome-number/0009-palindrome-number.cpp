
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
       return false;
       long int c=x,r=0,s=0;
        while(x!=0)
        {
r=x%10;
s= s*10 + r;
x=x/10; 
        }
        if(c==s)
        return true;
        else 
        return false;}};