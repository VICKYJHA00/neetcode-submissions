class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int r,int c,int dr[], int dc[]){
        visited[r][c] = 1;
        for(int i = 0;i<4;i++ ){
            int nr = r + dr[i],nc = c + dc[i];
            if( (nr >= 0 && nr<board.size()) && (nc >= 0 && nc<board[0].size()) && !visited[nr][nc] && board[nr][nc] =='O' ){
                dfs(board,visited,nr,nc,dr,dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int dr[] = {0,0,1,-1}; int dc[] = {1,-1,0,0};
        for(int i = 0;i<m;i++){
            if(board[0][i] == 'O' && !visited[0][i]){
                dfs(board,visited,0,i,dr,dc);
            }
            if(board[n-1][i] == 'O' && !visited[n-1][i]){
                dfs(board,visited,n-1,i,dr,dc);
            }
        }
        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(board,visited,i,0,dr,dc);
            }
            if(board[i][m-1] == 'O' && !visited[i][m-1]){
                dfs(board,visited,i,m-1,dr,dc);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
