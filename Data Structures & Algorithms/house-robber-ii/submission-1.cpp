class Solution {
   public:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i > n) return 0;

        if (dp[i] != -1) return dp[i];

        int incl = nums[i] + solve(i + 2, n, nums, dp);
        int excl = solve(i + 1, n, nums, dp);

        return dp[i] = max(incl, excl);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(solve(0, nums.size() - 2, nums, dp1), solve(1, nums.size() - 1, nums, dp2));
    }
};
