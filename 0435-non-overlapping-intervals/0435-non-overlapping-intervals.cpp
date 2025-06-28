class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;  // At least one interval is always non-overlapping
        int ansEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= ansEnd) {
                count++;
                ansEnd = intervals[i][1];
            }
        }

        return intervals.size() - count; // Total removals = total - max non-overlapping
    }
};
