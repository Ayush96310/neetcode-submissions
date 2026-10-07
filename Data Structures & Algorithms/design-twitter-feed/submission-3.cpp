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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=(int)tweets[userId].size()-1;i>=max((int)tweets[userId].size()-10,0);i--){
            pq.push(tweets[userId][i]);
        }
        for(auto &t:followList[userId]){
            for(int i=(int)tweets[t].size()-1;i>=max((int)tweets[t].size()-10,0);i--){
                if(pq.size()<10) pq.push(tweets[t][i]);
                else{
                    if(tweets[t][i].first>pq.top().first){
                        pq.pop();
                        pq.push(tweets[t][i]);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
