class Solution {
    bool isSymetrichelp(TreeNode* l, TreeNode* r){
        // Case 1: both are NULL
        if(!l && !r){return true;}

        // Case 2: both non-null and values match
        if(l && r && l->val==r->val){
            // Mirror check: l->right vs r->left, and l->left vs r->right
            return isSymetrichelp(l->right,r->left) && 
                   isSymetrichelp(l->left,r->right);
        }

        // Case 3: mismatch (one is null or values not equal)
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;  // empty tree is symmetric
        }
        return isSymetrichelp(root->left,root->right);
    }
};
