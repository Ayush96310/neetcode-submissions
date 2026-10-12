class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto [row,col,time] = q.front();
            q.pop();
            ans = max(ans,time);
            vector<int> drow = {-1,1,0,0};
            vector<int> dcol = {0,0,-1,1};
            for(int i=0; i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol,time+1});
                }
            }
        }
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
