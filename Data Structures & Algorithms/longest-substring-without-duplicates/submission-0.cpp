class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left  = 0, maxlen = 0, size = s.length();
        vector<int> seen(256,-1);
        for(int right = 0;right <size;right++){
            char ch = s[right];
            if(seen[ch] >= left) left = seen[ch]+1;
            maxlen = max(maxlen,right-left+1);
            seen[ch] = right;
        }
        return maxlen;
    }
};
