class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , maxlen = 0, n = s.length();
        vector<int> seen(256,-1);
        for(int r = 0;r<n;r++){
            char ch = s[r];
            if(seen[ch] >= l) l = seen[ch] + 1;
            maxlen = max(maxlen,r-l+1);
            seen[ch] = r;
        }

        return maxlen;


    }
};