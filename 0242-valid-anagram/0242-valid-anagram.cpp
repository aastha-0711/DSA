class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq;

        // Count characters in s
        for (char c : s) {
            freq[c]++;
        }

        // Subtract character counts using t
        for (char c : t) {
            freq[c]--;
            if (freq[c] < 0) return false; // More of char in t than in s
        }

        return true;  // All counts should be zero now
    }
};
