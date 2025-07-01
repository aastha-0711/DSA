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
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode*node, int &res){
        if(!node){return 0;}
        int leftsum=max(0,dfs(node->left,res));
        int rightsum=max(0,dfs(node->right,res));
res=max(res,leftsum+rightsum+node->val);
return max(leftsum,rightsum)+node->val;
    }
};