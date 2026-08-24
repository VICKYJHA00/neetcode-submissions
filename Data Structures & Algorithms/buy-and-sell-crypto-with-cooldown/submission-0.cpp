class Solution {
public:
    // buy == 1 mean can purchase but cant sell 
    // buy == 0 mean cant purchase but can sell
    int solve(int i ,vector<int>& prices,vector<vector<int>>& dp,int buy){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if (buy) {
            int incl = -prices[i] + solve(i + 1, prices, dp, 0);
            int excl = solve(i + 1, prices, dp, 1);

            return dp[i][buy] = max(incl, excl);
        }
        else {
            int incl = prices[i] + solve(i + 2, prices, dp, 1);
            int excl = solve(i + 1, prices, dp, 0);

            return dp[i][buy] = max(incl, excl);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        return solve(0,prices,dp,1);

    }
};
