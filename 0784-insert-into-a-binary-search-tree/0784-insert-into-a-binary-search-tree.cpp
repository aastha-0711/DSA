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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val); // insert as root if empty

        TreeNode* curr = root;

        while (true) {
            if (val < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(val);
                    break;
                } else {
                    curr = curr->left;
                }
            } else { // val > curr->val
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(val);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }
};
