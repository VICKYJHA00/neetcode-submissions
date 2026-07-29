class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string& str, int s,int e){
        if(s>=e) return true;
        if(dp[s][e] != -1) return dp[s][e];
        if(str[s] != str[e]) return false;
        return dp[s][e] = isPalindrome(str,s+1,e-1);
    }
    int countSubstrings(string s) {
        int n = s.length(), cnt = 0;
        dp.assign(n, vector<int>(n, -1));
        for(int i = 0;i<s.length();i++){
            for(int j = i;j<s.length();j++){
                if(isPalindrome(s,i,j)) cnt++;
            }
        }
        return cnt;        
    }
};
