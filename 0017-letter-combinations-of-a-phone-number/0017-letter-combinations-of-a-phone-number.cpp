class Solution {
    private:
    void backtrack(string& digits, int index, string& current, vector<string>& result, vector<string>& mapping) {
            if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
for (char letter : letters) {
    current.push_back(letter);
    backtrack(digits, index + 1, current, result, mapping);
    current.pop_back(); // backtrack
}

    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping = {
            "",     "",     "abc", "def",  // 0,1,2,3
            "ghi", "jkl", "mno", "pqrs",  // 4-7
            "tuv", "wxyz"                 // 8-9
        };
       vector<string> result;
        string current = "";
        backtrack(digits, 0, current, result, mapping);
        return result;
    }
};