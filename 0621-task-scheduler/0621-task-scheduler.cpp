class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(char task : tasks) {
            mpp[task]++;
        }

        priority_queue<int, vector<int>> pq;
        for(auto& it : mpp) {
            pq.push(it.second);
        }

        queue<pair<int, long long>> cooldown; // pair of <count, available_time>
        long long time = 0;

        while(!pq.empty() || !cooldown.empty()) {
            time++;
            
            if(!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                cnt--;
                if(cnt > 0) {
                    cooldown.push({cnt, time + n});
                }
            }

            if(!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return (int)time; // Safe to cast back to int at the end
    }
};
