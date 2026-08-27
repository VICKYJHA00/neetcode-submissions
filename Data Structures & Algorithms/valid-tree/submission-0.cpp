class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> visit;
        queue<pair<int,int>> q;
        q.push({0,-1});
        visit.insert(0);

        while(!q.empty()){
            auto[node,parent] = q.front();q.pop();
            for(int nei : adj[node]){
                if(nei ==  parent) continue;
                if(visit.count(nei)) return false;
                visit.insert(nei);
                q.push({nei,node});
            }
        }

        return visit.size() == n;
    }
};
