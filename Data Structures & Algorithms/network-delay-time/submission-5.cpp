class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mpp;
        for(auto& edges:times){
            int u = edges[0]; int v = edges[1]; int t = edges[2];
            mpp[u].push_back({v,t});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n+1,INT_MAX);
        pq.push({0,k});
        vis[k] = 0;
        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();
            if (t > vis[node]) continue;
            for(auto vec:mpp[node]){
                int des = vec.first; int w = vec.second;
                if(vis[des]>w+t){
                    vis[des] = w+t;
                    pq.push({w+t,des});
                }
            }          
        }
        int ans = INT_MIN;
        for(int i=1; i<=n;i++){
            if(vis[i]==INT_MAX) return -1;
            ans = max(ans,vis[i]);
        }
        return ans;
    }
};
