class Solution {
private:
    bool solve(int start, string& s, unordered_set<string>& dict, unordered_map<int, bool>& memo) {
        if (start == s.size()) return true;
        if (memo.find(start) != memo.end()) return memo[start];

        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (dict.count(word) && solve(end, s, dict, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return solve(0, s, dict, memo);
    }
};
