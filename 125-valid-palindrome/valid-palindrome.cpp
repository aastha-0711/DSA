class Solution {
public:
    // Helper function to check palindrome recursively
    bool isPalindromeHelper(const string& s, int left, int right) {
        if (left >= right) return true;
        if (s[left] != s[right]) return false;
        return isPalindromeHelper(s, left + 1, right - 1);
    }

    bool isPalindrome(string s) {
        string cleaned;

        // Clean the string: remove non-alphanumeric and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // Call the recursive helper
        return isPalindromeHelper(cleaned, 0, cleaned.size() - 1);
    }
};
