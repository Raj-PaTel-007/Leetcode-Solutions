class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        const int MAXF = 1500;

        vector<int> freq(MAXF + 1, 0);

        for (auto &x : items)
            freq[x[0]]++;

        vector<int> bonus(n);

        for (int i = 0; i < n; i++) {
            int f = items[i][0];

            int cnt = 0;
            for (int m = f; m <= MAXF; m += f)
                cnt += freq[m];

            bonus[i] = cnt - 1;
        }

        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int cost = items[i][1];

            vector<int> ndp = dp;
            for (int b = 0; b + cost <= budget; b++) {
                if (dp[b] < 0) continue;

                ndp[b + cost] =
                    max(ndp[b + cost],
                        dp[b] + 1 + bonus[i]);
            }
            for (int b = cost; b <= budget; b++) {
                ndp[b] =
                    max(ndp[b],
                        ndp[b - cost] + 1);
            }

            dp.swap(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};