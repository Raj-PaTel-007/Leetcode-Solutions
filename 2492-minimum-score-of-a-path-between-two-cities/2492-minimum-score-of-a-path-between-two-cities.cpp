vector<int>par;
vector<int>sz;

class DSU{
    public:
    DSU(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int findpar(int node){
        if(node == par[node]) return node;
        return par[node] = findpar(par[node]);
    }

    void combine(int a , int b){
        a = findpar(a);
        b = findpar(b);
        if(sz[a] >= sz[b]){
            par[b] = a;
            sz[a] += sz[b];
        }
        else{
            par[a] = b;
            sz[b] += sz[a];
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU ds(n);
        for(auto it : roads){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            if(ds.findpar(a) != ds.findpar(b)){
                ds.combine(a,b);
            }
        }
        sort(roads.begin(),roads.end(),[&](vector<int>&a , vector<int>&b){
            return a[2] < b[2];
        });
        for(auto it : roads){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            if(ds.findpar(a) == ds.findpar(1)) return c;
        }
        return -1;
    }
};