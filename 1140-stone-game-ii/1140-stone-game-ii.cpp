#define ll long long int

class Solution {
public:
    vector<int> pre;
    vector<vector<ll>> dp;

    ll fun(int idx, int m, vector<int>& arr) {
        int n = arr.size();

        if (idx >= n)
            return 0;

        if (dp[idx][m] != -1)
            return dp[idx][m];

        ll k = idx > 0 ? pre[idx - 1] : 0;
        ll ans = -1e18;

        for (int x = 1; x <= 2 * m; x++) {
            if (idx + x <= n) {
                ll take = pre[idx + x - 1] - k;

                ans = max(ans, take - fun(idx + x, max(m, x), arr));
            }
        }

        return dp[idx][m] = ans;
    }

    int stoneGameII(vector<int>& arr) {
        int n = arr.size();

        pre.resize(n);
        pre[0] = arr[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + arr[i];

        dp.assign(n, vector<ll>(n + 1, -1));

        ll diff = fun(0, 1, arr);

        return (pre[n - 1] + diff) / 2;
    }
};