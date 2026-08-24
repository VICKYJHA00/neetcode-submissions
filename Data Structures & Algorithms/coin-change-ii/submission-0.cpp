class Solution {
public:
    int solve(int i ,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(i >= coins.size() || amount < 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];
        int incl = solve(i,amount-coins[i],coins,dp);
        int excl = solve(i+1,amount,coins,dp);

        return dp[i][amount] = incl + excl;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};
