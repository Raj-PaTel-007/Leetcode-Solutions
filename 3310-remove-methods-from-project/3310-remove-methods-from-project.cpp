class Solution {
public:
    int cnt1 = 0;
    int cnt2 = 0;
    vector<int>ans;
    void dfs1(int node,vector<vector<int>>&adj,vector<bool>&vis1){
        vis1[node] = true;
         cnt1++;
        for(auto it : adj[node]){
            if(!vis1[it]){
                dfs1(it,adj,vis1);
            }
        }
    }
    void dfs2(int node,vector<vector<int>>&adj,vector<bool>&vis2){
        vis2[node] = true;
        ans.push_back(node);
        cnt2++;
        for(auto it : adj[node]){
            if(!vis2[it]) dfs2(it,adj,vis2);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>&arr) {
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(n);
        for(auto it : arr){
            adj1[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
            adj2[it[0]].push_back(it[1]);
        }
        vector<int>temp;
        vector<bool>vis1(n,false);
        vector<bool>vis2(n,false);
        dfs1(k,adj1,vis1);
        dfs2(k,adj2,vis2);
        if(cnt1 != cnt2) temp = ans;
        for(int i=0;i<n;i++){
            if(!vis2[i])temp.push_back(i);
        }
        return temp;
    }
};