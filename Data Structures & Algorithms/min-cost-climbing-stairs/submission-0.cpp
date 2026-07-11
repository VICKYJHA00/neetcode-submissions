class Solution {
   public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];

        return dp[index] = nums[index] + min(solve(index + 2, nums, dp),solve(index + 1,nums,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return min(solve(0, cost, dp),solve(1,cost,dp));
    }
};
