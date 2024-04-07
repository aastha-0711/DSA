class Solution {
public:
    bool checkValidString(string s) {
    
        int minOpen = 0;
        int maxOpen = 0;

        for(int i=0; i<s.length(); i++){
            
            char current =s[i];

            if(current == ')'){
                minOpen--;
                maxOpen--;
            }

            if(current == '('){
                minOpen++;
                maxOpen++;
            }

       
            if(current == '*'){
                minOpen--;
                maxOpen++;
            }

            if(maxOpen < 0) return false; 

            minOpen = max(0, minOpen);
        }

        if(minOpen==0)
        {
            return true;
        }
        else{return false;}

    }

};