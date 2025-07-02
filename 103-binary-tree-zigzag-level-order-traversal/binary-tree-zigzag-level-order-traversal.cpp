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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool lr=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>ans(size);
            for(int i=0;i<size;i++){
                TreeNode* top=q.front();
                q.pop();
                int index=lr?i:size-1-i;
             ans[index]  =top->val;
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){q.push(top->right);}
            }lr=!lr;
            res.push_back(ans);
        }return res;
    }
};