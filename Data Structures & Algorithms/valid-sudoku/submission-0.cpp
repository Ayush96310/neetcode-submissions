class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9;i++){
            vector<int> hash(10,0);
            for(int j=0; j<9;j++){
                if(board[i][j]!='.'){
                    if(hash[board[i][j]-'0']>0) return false;
                    hash[board[i][j]-'0']++;
                }
            }
        }
        for(int i=0; i<9;i++){
            vector<int> hash(10,0);
            for(int j=0; j<9;j++){
                if(board[j][i]!='.'){
                    if(hash[board[j][i]-'0']>0) return false;
                    hash[board[j][i]-'0']++;
                }
            }
        }
        for(int i=0; i<9;i++){
            vector<int> hash(10,0);
            for(int j=0+3*(i%3); j<3+3*(i%3);j++){
                for(int k=0+3*(i/3);k<3+3*(i/3);k++){
                    if(board[j][k]!='.'){
                        if(hash[board[j][k]-'0']>0) return false;
                        hash[board[j][k]-'0']++;
                    }
                }
            }
        }
        return true;
    }
};
