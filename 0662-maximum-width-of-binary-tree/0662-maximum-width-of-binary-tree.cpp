class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;

        // Use unsigned long long to avoid overflow
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long mmin = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                unsigned long long cur = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = cur;
                if (i == size - 1) last = cur;

                if (node->left)
                    q.push({node->left, cur * 2 + 1});
                if (node->right)
                    q.push({node->right, cur * 2 + 2});
            }

            ans = max(ans, int(last - first + 1)); // convert to int if needed
        }

        return ans;
    }
};
