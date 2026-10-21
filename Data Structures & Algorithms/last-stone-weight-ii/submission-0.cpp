class Solution {
public:
    vector<vector<int>> dp;
    int lastStoneWeightII(vector<int>& stones) {
        int totalsum = accumulate(stones.begin(),stones.end(),0);
        int target = (totalsum + 1)/2;
        dp.assign(stones.size(),vector<int>(target+1,-1));
        return solve(0,0,stones,totalsum,target);
    }

    int solve(int i,int total,vector<int>& stones,int stonesum,int target){
        if(total >= target || i == stones.size()){
            return abs(total - (stonesum - total));
        }
        if(dp[i][total] != -1) return dp[i][total];

        dp[i][total] = min(
            solve(i+1,total,stones,stonesum,target),
            solve(i+1,total+stones[i],stones,stonesum,target)
        );

        return dp[i][total];

    }
};