class Solution {
    stack<TreeNode*> st;   // for next (in-order)
    stack<TreeNode*> st2;  // for prev (reverse in-order)

    // In-order: smallest to largest
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    // Reverse in-order: largest to smallest
    void pushRight(TreeNode* node) {
        while (node) {
            st2.push(node);
            node = node->right;
        }
    }

    int getNext() {
        TreeNode* node = st.top(); st.pop();
        pushLeft(node->right);  // next larger is leftmost of right child
        return node->val;
    }

    int getPrev() {
        TreeNode* node = st2.top(); st2.pop();
        pushRight(node->left);  // next smaller is rightmost of left child
        return node->val;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        pushLeft(root);   // smallest
        pushRight(root);  // largest

        int leftVal = getNext();
        int rightVal = getPrev();

        while (leftVal < rightVal) {
            int sum = leftVal + rightVal;
            if (sum == k) return true;
            else if (sum < k) leftVal = getNext();
            else rightVal = getPrev();
        }

        return false;
    }
};
