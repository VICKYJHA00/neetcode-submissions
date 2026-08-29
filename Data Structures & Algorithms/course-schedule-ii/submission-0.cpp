class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto& it : prerequisites){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int finish = 0;
        vector<int> ans(numCourses);
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans[numCourses-finish-1] = node;
            finish++;
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        if( finish == numCourses ) return ans;
        return {};
    }
};

