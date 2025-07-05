class BSTIterator {
    stack<TreeNode*> st;

    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        if (!hasNext()) throw std::out_of_range("No next element");

        TreeNode* curr = st.top();
        st.pop();
        pushAll(curr->right);
        return curr->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
