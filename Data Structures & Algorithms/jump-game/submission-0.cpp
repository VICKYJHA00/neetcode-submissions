class Solution {
public:
    bool solve(int i ,vector<int>& nums,vector<int>& dp){
        if(i>= nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = 1;j<=nums[i];j++){
            if(solve(j+i,nums,dp)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};
