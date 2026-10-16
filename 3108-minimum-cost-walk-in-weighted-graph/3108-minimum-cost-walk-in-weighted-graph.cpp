class DSU{
    public:
    vector<int>par;
    vector<int>sz;
    DSU(int n){
       par.resize(n);
       sz.resize(n);
       for(int i=0;i<n;i++){
         par[i] = i;
         sz[i] = 1;
       }
    }
    int findpar(int node){
        if(par[node] == node)return node;
        return par[node] = findpar(par[node]);
    }

    void unite(int u,int v){
        int a = findpar(u);
        int b = findpar(v);
        if(a != b){
            if(sz[a] > sz[b]){
                par[b] = a;
                sz[a] += sz[b];
            }
            else{
                par[a] = b;
                sz[b] += sz[a];
            }
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        DSU ds(n);
        vector<vector<int>>adj(n);

        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            ds.unite(a,b);
            adj[a].push_back(c);
            adj[b].push_back(c);
        }

        vector<vector<int>>temp(n);

        for(int i=0;i<n;i++){
            temp[ds.findpar(i)].push_back(i);
        }

        vector<int>ans(n,-1);

        for(int i=0;i<n;i++){
            if(temp[i].size() == 0)continue;

            int a = -1;

            for(auto it : temp[i]){
                for(auto p : adj[it]){
                    if(a == -1) a = p;
                    else a = (a & p);
                }
            }

            ans[i] = a;
        }

        vector<int>raj;

        for(auto it : q){
            int q1 = it[0];
            int q2 = it[1];

            int a = ds.findpar(q1);
            int b = ds.findpar(q2);

            if(a == b){
                if(q1 == q2 && ans[a] == -1)
                    raj.push_back(0);
                else
                    raj.push_back(ans[a]);
            }
            else{
                raj.push_back(-1);
            }
        }

        return raj;
    }
};