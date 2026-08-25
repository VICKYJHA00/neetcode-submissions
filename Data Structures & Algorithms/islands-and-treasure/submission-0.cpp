class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i =0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
                // if(grid[nr][nc] == -1) continue;
        }
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                int nr = r + dr[i], nc = c + dc[i];

                if(nr < 0 || nr >= grid.size() ||
                nc < 0 || nc >= grid[0].size())
                    continue;

                if(grid[nr][nc] == -1) continue;
                if(grid[nr][nc] != INT_MAX) continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
};
