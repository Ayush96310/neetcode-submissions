class Solution {
public:
    void area(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, vector<int> &cnt){
        vis[row][col]=1;
        cnt[0]++;
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,-1,1};
        for(int i=0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol] && !vis[nrow][ncol]){
                area(grid,vis,nrow,ncol,cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    vector<int> cnt = {0};
                    area(grid,vis,i,j,cnt);
                    ans = max(ans,cnt[0]);
                }
            }
        }
        return ans;
    }
};
