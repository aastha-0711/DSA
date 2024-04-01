class Solution {
public:
    bool isValid(string s) {
    int l=s.length();
        stack<char> temp;
        for(int i=0;i<s.size();i++)
        {
if(temp.empty())
{
    temp.push(s[i]);
}
            else if((temp.top()=='(' and s[i]==')')
                or(temp.top()=='{' and s[i]=='}')
                    or (temp.top()=='[' and s[i]==']'))
            {
                temp.pop();
            }
            else{
                temp.push(s[i]);
            }
        }
        if(temp.empty())
        {
            return true;
        }return false;
    }
        
        
       
};