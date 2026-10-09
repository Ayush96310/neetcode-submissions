class Solution {
public:
    bool check(vector<vector<char>>& board, string &word, int row, int col, int pointer,vector<vector<int>>& vis){
        if(word[pointer]!=board[row][col]){
            return false;
        }
        if(pointer==word.size()-1) return true;
        vis[row][col]=1;
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,-1,1};
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                if(check(board,word,nrow,ncol,pointer+1,vis)){
                    vis[row][col]=0;
                    return true;
                }
            }
        }
        vis[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(board[i][j]==word[0]){
                    if(check(board,word,i,j,0,vis)) return true;
                }
            }
        }
        return false;
    }
};
