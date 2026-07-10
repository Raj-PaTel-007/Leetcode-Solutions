class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

    
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(n + 1, vector<int>(LOG, n));

        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < n && arr[p].first - arr[i].first <= maxDiff)
                p++;
            up[i][0] = p-1;
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = pos[q[0]];
            int r = pos[q[1]];
             
            if (l > r) swap(l, r);
            if(l==r){
                ans.push_back(0);
                continue;
            }
            int jumps = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[l][j] < r) {
                    l = up[l][j];
                    jumps += (1 << j);
                }
            }

            if (up[l][0] >= r)
                ans.push_back(jumps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
