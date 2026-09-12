class Solution {
public:
    vector<vector<int>> dp;

    int fun(int idx, int sum, vector<int>& a, int num) {
        if (sum == num)
            return 0;

        if (sum > num || idx == a.size())
            return 1e9;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int take = 1 + fun(idx, sum + a[idx], a, num);

        int notTake = fun(idx + 1, sum, a, num);

        return dp[idx][sum] = min(take, notTake);
    }

    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;

        vector<int> a;

        for (int x = k; x <= num; x += 10) {
            if (x != 0)
                a.push_back(x);
        }

        dp.assign(a.size() + 1, vector<int>(num + 1, -1));

        int ans = fun(0, 0, a, num);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};