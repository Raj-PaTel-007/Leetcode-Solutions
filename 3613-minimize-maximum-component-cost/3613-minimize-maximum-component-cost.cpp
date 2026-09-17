class Solution {
public:
    vector<int> par;

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;

        par[b] = a;
        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        par.resize(n);
        for(int i = 0; i < n; i++)
            par[i] = i;

        vector<int> v;

        for(auto &e : edges) {
            if(unite(e[0], e[1])) {
                v.push_back(e[2]);

                if(v.size() == n - 1)
                    break;
            }
        }

        sort(v.begin(), v.end());

        int ans = 0;

        for(int i = 0; i < n-k; i++)
            ans = max(ans, v[i]);

        return ans;
    }
};