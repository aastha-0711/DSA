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
    bool isSymetrichelp(TreeNode* l, TreeNode* r){
        if(l==nullptr || r==nullptr){
            return l==r;
        }
        if(l->val!=r->val){
            return false;
        }
        return isSymetrichelp(l->left,r->right) && isSymetrichelp(l->right,r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
          if(root==nullptr){
            return true;
        }
        return isSymetrichelp(root->left,root->right);

    }
};