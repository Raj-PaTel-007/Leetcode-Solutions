class Solution {
public:
    vector<int>toposort(vector<vector<int>>&arr,int k){
        vector<vector<int>>adj(k+1);
        vector<int>in(k+1,0);
        for(auto it : arr){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        vector<int>topo;
        queue<int>q;
        for(int i=1;i<=k;i++){
           if(in[i] == 0){
            q.push(i);
            topo.push_back(i);
           }
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(auto it : adj[a]){
               in[it]--;
               if(in[it] == 0){
                q.push(it);
                topo.push_back(it);
               }
            }
        }
        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions){
        vector<int>v1 = toposort(rowConditions,k);
        vector<int>v2 = toposort(colConditions,k);
        vector<vector<int>>ans(k,vector<int>(k,0));
        if(v1.size() != k || v2.size() != k) return {};
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[v1[i]] = i;
        }
        for(int i=0;i<k;i++){
            int el = v2[i];
            int x = mp[el];
            int y = i;
            ans[x][y] = el;
        }
        return ans;
    }
};