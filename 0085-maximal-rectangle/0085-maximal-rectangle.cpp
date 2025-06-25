class Solution {
private:
    int lhist(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                ans = max(ans, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            ans = max(ans, heights[element] * (nse - pse - 1));
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Initialize prefix sum matrix
        vector<vector<int>> psum(rows, vector<int>(cols, 0));

        // Compute psum column-wise
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                psum[i][j] = sum;
            }
        }

        // Now compute max histogram area row-wise
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            ans = max(ans, lhist(psum[i]));
        }

        return ans;
    }
};
