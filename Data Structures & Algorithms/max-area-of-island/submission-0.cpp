class Solution {
    public:
    void dfs(int r,int c,vector<vector<int>>& visited,vector<vector<int>>& grid,int& cnt){
        visited[r][c] = 1;
        cnt++;
        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};
        for(int i =0;i<4;i++){
            int nr = r + dr[i],nc = c + dc[i];
            if((nr>=0 && nr<grid.size()) && (nc>=0 && nc<grid[0].size()) && !visited[nr][nc] && grid[nr][nc] == 1 ){
                dfs(nr,nc,visited,grid,cnt);
            }
        }
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int maxArea = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i,j,visited,grid,cnt);
                    maxArea = max(maxArea,cnt);
                }
            }
        }
        return maxArea;
    }
};
