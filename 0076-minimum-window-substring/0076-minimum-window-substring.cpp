class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};  // For frequency of characters in t

        for (char ch : t) {
            hash[ch]++;
        }

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = -1;
        int count = t.length();

        while (r < s.length()) {
            // If character s[r] is needed
            if (hash[s[r]] > 0) {
                count--;
            }
            // Decrease hash anyway, even if it goes negative
            hash[s[r]]--;
            r++;

            // All characters matched
            while (count == 0) {
                // Update min window
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                // Try to shrink from left
                hash[s[l]]++;

                // If character becomes useful again, increase count
                if (hash[s[l]] > 0) {
                    count++;
                }

                l++;
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};
