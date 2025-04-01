class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;  // To store extracted words
        string word, result;
        int n = s.size();

        // Step 1: Extract words from the string
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {  
                word += s[i];  // Build the current word
            } else if (!word.empty()) {  
                words.push_back(word);  // Store completed word
                word.clear();  // Reset word for next one
            }
        }

        // Store last word if exists
        if (!word.empty()) words.push_back(word);

        // Step 2: Construct the reversed string
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];  // Append word in reverse order
            if (i != 0) result += " ";  // Add space between words
        }

        return result;  // Return final reversed words string
    }
};
