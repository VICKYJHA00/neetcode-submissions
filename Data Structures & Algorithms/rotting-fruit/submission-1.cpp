class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int freshOranges = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1)  freshOranges++;
            }
        }

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        int time = 0;
        while(!q.empty() && freshOranges>0){
            int size = q.size();
            while(size--){
                auto[row,col] = q.front();
                q.pop();
                for(int i = 0;i<4;i++){
                    int nr = row + dr[i],  nc = col + dc[i];
                    if((nr>=0 && nr < grid.size()) && (nc >= 0 && nc < grid[0].size() ) && grid[nr][nc] == 1 ){
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                        freshOranges--;
                    }
                }
            }
            time++;
        }

        return (freshOranges == 0) ?  time : -1;
    }
};
