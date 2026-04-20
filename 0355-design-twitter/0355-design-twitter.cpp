class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        following[userId].insert(userId);

        for(int user : following[userId]) {
            for(auto &t : tweets[user]) {
                pq.push(t);
            }
        }

        vector<int> res;

        int count = 0;
        while(!pq.empty() && count < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};