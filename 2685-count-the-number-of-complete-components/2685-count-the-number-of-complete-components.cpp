class Solution {
public:

    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,int &nodecount , int& edgecount){
         vis[node] = true;
         nodecount++;
         for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,nodecount,edgecount);
            }
             edgecount++;
         }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodecount = 0;
                int edgecount = 0;
                dfs(i,adj,vis,nodecount,edgecount);
                if(edgecount == (nodecount*(nodecount-1))) ans++;
            }
        }
        return ans;
    }
};