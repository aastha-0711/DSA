class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        using std::isalnum;
        using std::tolower;
        for(char c:s){
            if(isalnum(c)){
                s2.push_back(tolower(c));
            }
        }
        int left=0;
        int right=s2.size()-1;
        while(left<right){
if(s2[right]!=s2[left]){
    return false;
}left++;
        right--;}
        return true;
    }
};