/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode* node, int& length) {
        if (!node) {
            return 0;
        }
        int right = height(node->right, length);
        int left = height(node->left, length);
        length = max(length, right + left);
        return 1 + max(right, left);        // Height of this node
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int length = 0;  // ❗ Must initialize to 0
        height(root, length);
        return length;
    }
};
