class Solution {
public:
    string removeKdigits(std::string num, int k) {
       stack<char> stack;
        
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
     reverse(result.begin(), result.end());
      int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }

        result = result.substr(start,result.size()-start+1);

        return result.empty() ? "0" : result;
    }};
    