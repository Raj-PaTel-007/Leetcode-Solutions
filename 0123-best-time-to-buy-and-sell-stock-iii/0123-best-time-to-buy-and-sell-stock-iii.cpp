class Solution {
public:
    int dp[100001][2][3];

    int solve(int idx, int buy, int cap, vector<int>& prices) {
        if (idx == prices.size() || cap == 0)
            return 0;

        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        int profit;

        if (buy) {
            profit = max(
                -prices[idx] + solve(idx + 1, 0, cap, prices),
                solve(idx + 1, 1, cap, prices)
            );
        } else {
            profit = max(
                prices[idx] + solve(idx + 1, 1, cap - 1, prices),
                solve(idx + 1, 0, cap, prices)
            );
        }

        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 2, prices);
    }
};