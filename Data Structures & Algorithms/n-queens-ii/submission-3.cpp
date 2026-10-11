class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board){
        // col prev
        for(int i = 0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        // diag above
        for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j-- ){
            if(board[i][j] =='Q') return false;
        }
        // low diag
        for(int i = row-1,j = col+1;i>=0 && j<board.size();i--,j++ ){
            if(board[i][j] =='Q') return false;
        }


        return true;
    }
    void solve(int r,int n,vector<string>& board,int& cnt){
        if(r == n){
            cnt++;
            return;
        }
        for(int i = 0;i<n;i++){
            if(isSafe(r,i,board)){
                board[r][i] = 'Q';
                solve(r+1,n,board,cnt);
                board[r][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int cnt =0 ;
        solve(0,n,board,cnt);
        return cnt;
    }
};