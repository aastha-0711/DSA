class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        for(int i = 0; i < arr.size(); i++) {
            maxh.push({(abs(arr[i] - x)), arr[i]});
            if(maxh.size() > k) {
                maxh.pop();
            }
        }

        vector<int> result;
        while(!maxh.empty()) {
            result.push_back(maxh.top().second);
            maxh.pop();
        }

        sort(result.begin(),result.end());

        return result;
    }
};