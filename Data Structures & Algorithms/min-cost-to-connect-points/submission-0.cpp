class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> distances(n);
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n;j++){
                int distance = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                distances[i].push_back({distance,j});
                distances[j].push_back({distance,i});
            }
        }
        int ans = 0;
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node] =  true;
            ans+=dis;
            for(auto t:distances[node]){
                if(!vis[t.second]){
                    pq.push(t);
                }
            }
        }
        return ans;
    }
};
