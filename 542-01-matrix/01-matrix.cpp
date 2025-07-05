class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        // Push all 0s to queue and set their result to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int xx = x + dx;
                int yy = y + dy;

                if (xx >= 0 && xx < m && yy >= 0 && yy < n && 
                    result[xx][yy] > result[x][y] + 1) {
                    result[xx][yy] = result[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }

        return result;
    }
};
