class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

        auto markSafe = [&](int i, int j) {
            stack<pair<int,int>> st;
            st.push({i,j});
            while (!st.empty()) {
                auto [x, y] = st.top(); st.pop();
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') continue;
                board[x][y] = 'T'; // Mark temporarily safe
                for (auto [dx, dy] : directions) {
                    st.push({x + dx, y + dy});
                }
            }
        };

        // Step 1: Mark border-connected 'O's
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') markSafe(i, 0);
            if (board[i][n - 1] == 'O') markSafe(i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') markSafe(0, j);
            if (board[m - 1][j] == 'O') markSafe(m - 1, j);
        }

        // Step 2: Flip all remaining 'O' to 'X', and 'T' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
