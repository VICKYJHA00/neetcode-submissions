class Solution {
public: 

    void addSol(vector<vector<int>>& board,vector<vector<string>>& output,int n){
        vector<string> temp(n,string(n,'.'));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 1){
                    temp[i][j] = 'Q';
                }
            }
        }
        output.push_back(temp);
    }
    bool isValid(int r, int c,vector<vector<int>>& board,int n){
        int x = r,y = c;
        while(x >= 0){
            if(board[x][y] == 1) return false;
            x--;
        }
        x = r,y = c;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1) return false;
            y--;
            x--;
        }
        x = r,y = c;
        while(x >= 0 && y < n){
            if(board[x][y] == 1) return false;
            y++;
            x--;
        }

        return true;
    }

    void solve(int r,int& n,vector<vector<string>>& output,vector<vector<int>>& board){
        if(r == n){
            addSol(board,output,n);
            return;
        }
        for(int c = 0;c<n;c++){
            if(isValid(r,c,board,n)){
                board[r][c] = 1;
                solve(r+1,n,output,board);
                board[r][c] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<vector<int>> board(n,vector<int>(n,0));

        solve(0,n,output,board);
        return output;
    }
};
