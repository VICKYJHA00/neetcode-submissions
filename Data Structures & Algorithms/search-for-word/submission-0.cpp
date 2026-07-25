class Solution {
   public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int index,
               vector<vector<bool>>& vis) {

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() )
            return false;
        if (vis[i][j]) return false;
        if (board[i][j] != word[index]) return false;
        if(word.size()-1 ==  index) return true;
        vis[i][j] = true;

        bool found = 
                    solve(board,word,i,j+1,index+1,vis) || 
                    solve(board,word,i,j-1,index+1,vis) || 
                    solve(board,word,i+1,j,index+1,vis) || 
                    solve(board,word,i-1,j,index+1,vis) ;

        vis[i][j] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0, vis)) return true;
                }
            }    
        }
        return false;
    }
};
