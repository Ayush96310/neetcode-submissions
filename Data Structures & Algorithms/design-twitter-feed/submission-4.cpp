class Twitter {
public:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> followList;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int userSize = tweets[userId].size();
        if(userSize){
            pq.push({tweets[userId][userSize-1].first,{userSize-1,userId}});
        }
        for(auto &followeeId:followList[userId]){
            int followeeSize = tweets[followeeId].size();
            if(followeeSize){
                pq.push({tweets[followeeId][followeeSize-1].first,{followeeSize-1,followeeId}});
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size()<10){
            auto [_,data] = pq.top();
            int ind = data.first;
            int uid = data.second;
            ans.push_back(tweets[uid][ind].second);
            pq.pop();
            if(ind){
                pq.push({tweets[uid][ind-1].first,{ind-1,uid}});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
