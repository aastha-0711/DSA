class MyStack {
    vector<int> stack;

public:
    MyStack() {
        // constructor: no initialization needed
    }

    void push(int x) {
        stack.push_back(x);
    }

    int pop() {
        if (!stack.empty()) {
            int topp = stack.back();
            stack.pop_back();
            return topp;
        }
        return -1;
    }

    int top() {
        if (!stack.empty()) {
            return stack.back();
        }
        return -1;
    }

    bool empty() {
        return stack.empty();  // ✅ FIXED
    }
};
