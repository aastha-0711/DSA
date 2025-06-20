class Solution {
private:
    bool recursiveSearch(int x, int i, int j, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (x == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[x] || visited[i][j]) {
            return false;
        }

        visited[i][j] = true; // FIXED
        bool found =
            recursiveSearch(x + 1, i, j - 1, word, board, visited) ||  // left
            recursiveSearch(x + 1, i, j + 1, word, board, visited) ||  // right
            recursiveSearch(x + 1, i - 1, j, word, board, visited) ||  // up
            recursiveSearch(x + 1, i + 1, j, word, board, visited);    // down

        visited[i][j] = false; // backtrack
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        unordered_map<char, int> boardFreq;
        for (const auto& row : board) {
            for (char ch : row) {
                boardFreq[ch]++;
            }
        }

        unordered_map<char, int> wordFreq;
        for (char ch : word) {
            wordFreq[ch]++;
        }

        for (const auto& entry : wordFreq) {
            if (entry.second > boardFreq[entry.first]) {
                return false;
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && recursiveSearch(0, i, j, word, board, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};
