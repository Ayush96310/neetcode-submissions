class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MIN;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto [val,row,col] = pq.top();
            pq.pop();
            vis[row][col]=true;
            ans = max(ans,val);
            if(row==n-1 && col==n-1){
                return ans;
            }
            vector<int> drow = {-1,1,0,0};
            vector<int> dcol = {0,0,-1,1};
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol]){
                    pq.push({grid[nrow][ncol],nrow,ncol});
                }
            }
        }
        return -1;
    }
};
