class Solution {
public:
    void solve(int n,int k,vector<int>& temp,int start,vector<bool>& visited,vector<vector<int>>& ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }else if(temp.size()>k) return;
        for(int i =start;i<=n;i++){
            if(visited[i]) continue;
            temp.push_back(i);
            visited[i] = true;
            solve(n,k,temp,i+1,visited,ans);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(n+1,false);
        solve(n,k,temp,1,visited,ans);
        return ans;
    }
};