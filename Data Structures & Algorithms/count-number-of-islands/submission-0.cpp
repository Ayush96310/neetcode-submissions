class Solution {
public:
    void mark(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col]=1;
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,-1,1};
        for(int i=0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                mark(grid,vis,nrow,ncol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    mark(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};
