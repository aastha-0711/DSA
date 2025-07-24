class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     int n = nums.size();
        vector<int> result(n, -1);  // Default is -1
        stack<int> st;  // Stack stores indices
for(int i=2*n-1;i>=0;i--){
int indx=i%n;
while (!st.empty() && st.top() <= nums[indx]) {
    st.pop();
}
if (!st.empty()) {
    result[indx] = st.top();
}
st.push(nums[indx]);
}
return result;
    }
};
