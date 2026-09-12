class Solution {
public:

    vector<vector<int>> dp;

    int fun(int idx, int sum, int val, int k, int num) {
        if (sum == num) return 0;
        if (sum > num) return INT_MAX - 1;
        if (idx > num) return INT_MAX - 1;

        if (dp[sum][val] != -1)
            return dp[sum][val];

        int ans = INT_MAX - 1;

        if (val == 0) {
            ans = min(ans, fun(idx, sum + k, k, k, num));
            ans = min(ans, 1 + fun(idx + 1, sum + k, 0, k, num));
        }
        else {
            string p = to_string(val);
            int a = p.size();

            for (int i = 1; i <= 9; i++) {
                int newVal = i * pow(10, a) + val;

                ans = min(ans,
                         fun(idx, sum - val + newVal,
                             newVal, k, num));

                ans = min(ans,
                         1 + fun(idx + 1, sum - val + newVal,
                             0, k, num));
            }
        }

        return dp[sum][val] = ans;
    }

    int minimumNumbers(int num, int k) {
        if (k == 0) {
            if (num == 0) return k;
            if (num % 10 != 0) return -1;
            return 1;
        }
       if(num % 10 == k) return 1;
        if (num == 0) return 0;

        dp.assign(num + 1,vector<int>(num + 1,-1));

        int ans = fun(0, 0, 0, k, num);

        if (ans >= 1e5) return -1;

        return ans + 1;
    }
};