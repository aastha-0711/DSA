class Solution {
public:
    bool checkValidString(string s) {
        int miny=0;
        int maxy=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                miny=miny+1;
                maxy+=1;
            }
            else if(s[i]==')'){
                miny-=1;
                maxy-=1;
            }
            else{
                maxy+=1;
                miny-=1;
            }
            if(miny<0){
                miny=0;
            }
            if(maxy<0){
                return false;
            }
        }
return miny==0?true:false;
    }
};