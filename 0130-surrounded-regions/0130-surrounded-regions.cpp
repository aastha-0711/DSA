class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        // Step 1: Push all border 'O' into the queue
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i,0});
                board[i][0] = 'T'; // mark visited safe
            }
            if (board[i][n-1] == 'O') {
                q.push({i,n-1});
                board[i][n-1] = 'T';
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push({0,j});
                board[0][j] = 'T';
            }
            if (board[m-1][j] == 'O') {
                q.push({m-1,j});
                board[m-1][j] = 'T';
            }
        }

        // Step 2: BFS flood-fill to mark all border-connected 'O' as 'T'
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int xx = x + dx, yy = y + dy;
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && board[xx][yy] == 'O') {
                    q.push({xx, yy});
                    board[xx][yy] = 'T';
                }
            }
        }

        // Step 3: Flip remaining 'O' -> 'X', and 'T' -> 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
