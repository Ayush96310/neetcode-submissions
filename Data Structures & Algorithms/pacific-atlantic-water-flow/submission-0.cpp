class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col){
        vis[row][col]=true;
        vector<int> drow = {0,0,-1,1};
        vector<int> dcol = {-1,1,0,0};
        for(int i=0; i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<heights.size() && ncol<heights[0].size() && heights[nrow][ncol]>=heights[row][col] && !vis[nrow][ncol]){
                dfs(heights,vis,nrow,ncol);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visPacific(m,vector<bool>(n,false));
        vector<vector<bool>> visAtlantic(m,vector<bool>(n,false));
        for(int i=0; i<n;i++){
            // pacific.push(heights[0][i]);
            if(!visPacific[0][i]) dfs(heights,visPacific, 0, i);
        }
        for(int i=1; i<m;i++){
            // pacific.push(heights[i][0]);
            if(!visPacific[i][0]) dfs(heights,visPacific, i, 0);
        }
        for(int i=0; i<n;i++){
            // pacific.push(heights[m-1][i]);
            if(!visAtlantic[m-1][i]) dfs(heights,visAtlantic,m-1,i);
        }
        for(int i=0; i<m-1;i++){
            // pacific.push(heights[i][n-1]);
            if(!visAtlantic[i][n-1]) dfs(heights,visAtlantic, i, n-1);
        }
        vector<vector<int>> ans;
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(visPacific[i][j] && visAtlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
