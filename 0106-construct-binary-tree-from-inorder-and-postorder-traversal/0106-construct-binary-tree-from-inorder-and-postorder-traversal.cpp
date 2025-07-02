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
    TreeNode* build(vector<int>& postorder, int postint, int postend,
                    vector<int>& inorder, int inint, int inend,
                    map<int, int>& mp) {
        if (postint > postend || inint > inend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postend]);
        int intind = mp[root->val];
        int numsleft = intind - inint;

        root->left = build(postorder, postint, postint + numsleft-1,
                           inorder, inint, intind - 1, mp);
        root->right = build(postorder, postint +numsleft, postend-1,
                            inorder, intind + 1, inend, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(postorder, 0, postorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mp);
    }
};