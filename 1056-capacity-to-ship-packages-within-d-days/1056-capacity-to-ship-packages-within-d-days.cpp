class Solution {
private:
    bool canShip(int capacity, vector<int>& weights, int days) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                dayCount++;
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return dayCount <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  // min possible capacity
        int high = accumulate(weights.begin(), weights.end(), 0);  // max possible capacity
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
