class Solution {
private:
    void dfs(int i,vector<int>& visited,vector<vector<int>>& adj){ 
        visited[i] = 1;
        for(auto neighbour : adj[i]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
