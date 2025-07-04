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
   bool bst(TreeNode*root, long min, long max){
        if(!root) return true;
        if(root->val<=min || root->val>=max){
            return false;
        }
        return bst(root->right,root->val, max) && bst(root->left, min, root->val);

    }
public:
    bool isValidBST(TreeNode* root) {
        return bst(root, LONG_MIN, LONG_MAX);
    }
};