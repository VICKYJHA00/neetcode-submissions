class Solution {
public:
    bool isSame(string ans,unordered_map<int,int> mp){
        for(char c : ans){
            mp[c]--;
        }
        for(auto c : mp){
            if(c.second != 0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(),l= 0;string ans = "";
        unordered_map<int,int> mp;
        for(char c : s1){
            mp[c]++;
        }
        for(int r =0 ;r<s2.length();r++){
            ans += s2[r];
            if(ans.length() > n){
                ans.erase(ans.begin());
                l++;
            }

            if(ans.length() == n && isSame(ans,mp)) return true;
        }
        return false;
    }
};
