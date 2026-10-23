class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t:flights){
            adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int> minStops(n,INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq; 
        pq.push({0,0,src});
        while(!pq.empty()){
            auto [cost,stops,port] = pq.top();
            pq.pop();
            if(port==dst) return cost;
            if(stops>=minStops[port]) continue;
            minStops[port]=stops;
            for(auto t:adj[port]){
                if(stops<=k){
                    pq.push({cost+t.second,stops+1,t.first});
                }
            }
        }
        return -1;
    }
};
