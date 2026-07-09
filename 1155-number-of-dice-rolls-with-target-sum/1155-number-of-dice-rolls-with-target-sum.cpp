#define ll long long
class Solution {
public:
    const int M = 1e9 + 7;
    vector<vector<int>> dp;

    int fun(int n, int k, int t) {
        if (n == 0 && t == 0) return 1;
        if (n == 0 || t < 0) return 0;

        if (dp[n][t] != -1) return dp[n][t];

        ll ans = 0;

        for (int i = 1; i <= k; i++) {
            ans = (ans + fun(n - 1, k, t - i)) % M;
        }

        return dp[n][t] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n + 1, vector<int>(target + 1, -1));
        return fun(n, k, target);
    }
};