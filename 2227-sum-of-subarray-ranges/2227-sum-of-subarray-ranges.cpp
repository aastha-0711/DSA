class Solution {
private:
    vector<int> findnse(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findpse(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    vector<int> findnge(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nge;
    }

    vector<int> findpge(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pge(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }
        return pge;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse = findnse(nums);
        vector<int> pse = findpse(nums);
        vector<int> nge = findnge(nums);
        vector<int> pge = findpge(nums);
        
        long long small = 0;
        long long large = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            small += left * right * 1LL * nums[i];
        }

        for (int j = 0; j < nums.size(); j++) {
            long long left = j - pge[j];
            long long right = nge[j] - j;
            large += left * right * 1LL * nums[j];
        }

        return large - small;
    }
};