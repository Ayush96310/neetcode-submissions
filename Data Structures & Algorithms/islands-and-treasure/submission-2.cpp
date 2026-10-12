class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(!grid[i][j]){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto [row,col,cnt] = q.front();
            q.pop();
            vector<int> drow = {-1,1,0,0};
            vector<int> dcol = {0,0,-1,1};
            for(int k=0; k<4;k++){
                int nrow = row+drow[k];
                int ncol = col+dcol[k];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==INT_MAX){
                    grid[nrow][ncol]=cnt+1;
                    q.push({nrow,ncol,cnt+1});
                }
            }
        }
    }
};
