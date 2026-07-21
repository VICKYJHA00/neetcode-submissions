class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int l = 0; int maxLen = 0; int maxFreq = 0;
        for(int r = 0;r<s.length();r++){
            int idx = s[r]-'A';
            freq[idx]++;
            maxFreq = max(maxFreq,freq[idx]);
            if((r-l+1) - maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};
