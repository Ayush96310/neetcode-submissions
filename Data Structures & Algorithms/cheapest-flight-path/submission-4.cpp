class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        for(int i=0; i<=k;i++){
            vector<int> temp = dis;
            for(auto &f:flights){
                int u = f[0];
                int v = f[1];
                int prices = f[2];
                if(dis[u]!=INT_MAX && dis[u]+prices<temp[v]){
                    temp[v]=dis[u]+prices;
                }
            }
            dis = temp;
        }
        return dis[dst]==INT_MAX ? -1:dis[dst];
    }
};
