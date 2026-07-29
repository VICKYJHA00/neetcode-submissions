class Solution {
public:
    bool rec(string s,string t,int i,int j,vector<vector<int>>& dp){
        if(i == s.length()) return true;
        if(j == t.length()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = rec(s,t,i+1,j+1,dp);
        return dp[i][j] = rec(s,t,i,j+1,dp);
    }

    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return rec(s,t,0,0,dp);
    }
};