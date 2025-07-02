class Solution {
    TreeNode* build(vector<int>& preorder, int preint, int preend,
                    vector<int>& inorder, int inint, int inend,
                    map<int, int>& mp) {
        if (preint > preend || inint > inend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preint]);
        int intind = mp[root->val];
        int numsleft = intind - inint;

        root->left = build(preorder, preint + 1, preint + numsleft,
                           inorder, inint, intind - 1, mp);
        root->right = build(preorder, preint + 1 + numsleft, preend,
                            inorder, intind + 1, inend, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mp);
    }
};
