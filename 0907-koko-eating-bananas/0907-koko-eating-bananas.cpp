class Solution {
private:
    long long count(vector<int> &piles, long long target){
        long long time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += (int)ceil((double)piles[i] / target);
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1;
        long long end = *max_element(piles.begin(), piles.end());
        long long ans = end;

        while(start <= end){
            long long mid = start + (end - start) / 2;
            long long total = count(piles, mid);

            if(total <= h){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return (int)ans;
    }
};
