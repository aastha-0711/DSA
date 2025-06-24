class Solution {
    private:
    vector<int> findnse(vector<int>&arr){
int n = arr.size();
        vector<int> nse(n, n); // default: no smaller element → virtual boundary
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
      nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>&arr){
 int n = arr.size();
        vector<int> pse(n, -1); // default: no smaller element to the left
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        int total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (arr[i] * left % mod * right % mod)) % mod;
        }

        return total;
    }
};