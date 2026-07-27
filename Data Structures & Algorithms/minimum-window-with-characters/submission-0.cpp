class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int m = s.length(), n = t.length();
        int si = 0, minlen = INT_MAX;
        int l = 0, cnt = 0;

        for (char c : t) hash[c]++;

        for (int r = 0; r < m; r++) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while (cnt == n) {
                if ((r - l + 1 < minlen)) {
                    minlen = r - l + 1;
                    si = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
        }
        if (minlen == INT_MAX) return "";
        return s.substr(si, minlen);
    }
};
