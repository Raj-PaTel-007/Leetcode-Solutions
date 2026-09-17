class Solution {
public:
    vector<int> dp;

    int fun(int idx, vector<vector<int>>& o) {
        int n = o.size();

        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = fun(idx + 1, o);

        int l = idx + 1, r = n;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(o[mid][0] >= o[idx][1])
                r = mid;
            else
                l = mid + 1;
        }

        ans = max(ans, o[idx][2] + fun(l, o));

        return dp[idx] = ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> o;

        for(int i = 0; i < n; i++) {
            o.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(o.begin(), o.end());

        dp.assign(n, -1);

        return fun(0, o);
    }
};