class Solution {
public: 
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1) return 1;
        if (i >= n || j >= m || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i+1,j,grid,dp)+solve(i,j+1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1 ) return 0;
        vector<vector<int>>dp (n,vector<int>(m,-1));
        return solve(0,0,obstacleGrid,dp);
    }
};