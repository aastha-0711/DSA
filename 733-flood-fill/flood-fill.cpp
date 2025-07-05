class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        // Early exit if the color is the same
        if (originalColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                // Check bounds and original color match
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == originalColor) {
                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }

        return image;
    }
};
