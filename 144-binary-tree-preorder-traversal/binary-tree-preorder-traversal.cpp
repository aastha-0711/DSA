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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        preorder(root,pre);
        return pre;
    }
    void preorder(TreeNode* node, vector<int>& pre) {
        if(!node)return;
        pre.push_back(node->val);
        preorder(node->left,pre);
        preorder(node->right, pre);
    }
};