class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int row, int col){
        vis[row][col]=true;
        vector<int> drow = {0,0,-1,1};
        vector<int> dcol = {-1,1,0,0};
        for(int i=0; i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(board,vis,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(int i=0; i<n;i++){
            if(board[0][i]=='O' && !vis[0][i]) dfs(board,vis,0,i);
        }
        for(int i=0; i<n;i++){
            if(board[m-1][i]=='O' && !vis[m-1][i]) dfs(board,vis,m-1,i);
        }
        for(int i=1; i<m-1;i++){
            if(board[i][0]=='O' && !vis[i][0]) dfs(board,vis,i,0);
        }
        for(int i=1; i<m-1;i++){
            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(board,vis,i,n-1);
        }
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
