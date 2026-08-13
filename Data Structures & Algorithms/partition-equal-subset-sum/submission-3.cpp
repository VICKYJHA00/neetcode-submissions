class Solution {
public:
    bool solve(int index,vector<int>& nums,vector<bool>& dp, int sum){
        if(sum == 0) return true;
    
        if(index == nums.size() || sum < 0) return false;
        if(dp[index] != false) return dp[index];
        int incl = solve(index+1,nums,dp,sum-nums[index]);
        int excl = solve(index+1,nums,dp,sum);

        return dp[index] =  incl || excl;
    }
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum%2 == 1) return false;
        sum = sum/2;
        vector<bool> dp(nums.size(),false);
        return  solve(0,nums,dp,sum);

    }
};
