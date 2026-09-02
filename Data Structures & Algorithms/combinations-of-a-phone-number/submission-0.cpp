class Solution {
public:
    void solve(int idx,vector<string>& keys,string temp,vector<string>& ans,string digits){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        int num = digits[idx]-'0';
        string alph = keys[num];
        int a = alph.size();
        for(int i = 0;i<a;i++){
            temp.push_back(alph[i]);
            solve(idx+1,keys,temp,ans,digits);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> ans;
        string temp = "";
        vector<string> keys = {{},{},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
        solve(0,keys,temp,ans,digits);
        return ans;
    }
};
