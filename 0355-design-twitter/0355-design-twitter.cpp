class Twitter {
    unordered_map<int, set<int>> follower; // follower -> set of followees
    unordered_map<int, vector<pair<int, int>>> tweetmap; // user -> vector of <time, tweetId>
    int time;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({++time, tweetId});
     
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int, int>> pq; // max-heap based on time
        if(tweetmap.find(userId)!=tweetmap.end()){
            for(int i=0;i<tweetmap[userId].size();i++){
                pq.push(tweetmap[userId][i]);
            }
        }
        for(auto it: follower[userId]){
            if(tweetmap.find(it)!=tweetmap.end()){
                for(int i=0;i<tweetmap[it].size();i++){
                    pq.push(tweetmap[it][i]);
                }
            }
        }


      while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // Prevent unfollowing self
            follower[followerId].erase(followeeId);
        
    }
};