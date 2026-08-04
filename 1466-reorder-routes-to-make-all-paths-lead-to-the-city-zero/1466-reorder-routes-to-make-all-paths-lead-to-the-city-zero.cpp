class Solution {
public:

    int cnt = 0;

    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj1,vector<vector<int>>&adj2){
        vis[node] = true;
        for(auto it : adj2[node]){
            if(!vis[it]) dfs(it,vis,adj1,adj2);
        }
        for(auto it : adj1[node]){
            if(!vis[it]){
                dfs(it,vis,adj1,adj2);
                cnt++;
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(n);
        for(auto it : connections){
            adj1[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        dfs(0,vis,adj1,adj2);
        return cnt;
    }
};