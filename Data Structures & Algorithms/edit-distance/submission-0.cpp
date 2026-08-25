class Solution {
public:
    int solve(int i,int j , string word1,string word2,vector<vector<int>>& dp){
        if(i == word1.length() ) return  word2.length()-j;
        if(j == word2.length()) return word1.length()-i;
        if(dp[i][j] != -1) return dp[i][j];
        int len = 0;
        if(word1[i] == word2[j]){
            len = solve(i+1,j+1,word1,word2,dp);
        }
        else{
            int del = 1 + solve(i,j+1,word1,word2,dp);
            int ins = 1 +solve(i+1,j,word1,word2,dp);
            int rep = 1 +solve(i+1,j+1,word1,word2,dp);
            len = min({del,ins,rep});
        }
        return dp[i][j] = len;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(0,0,word1,word2,dp);
    }
};
