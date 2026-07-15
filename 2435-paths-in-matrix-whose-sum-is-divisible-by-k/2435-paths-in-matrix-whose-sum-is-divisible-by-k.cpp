#define ll long long int

class Solution {
public:

    ll M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(k, 0)));
        for(int sum = 0; sum < k; sum++) {
            if((sum + grid[n-1][m-1]) % k == 0) {
                dp[n-1][m-1][sum] = 1;
            }
        }
        for(int row = n-1; row >= 0; row--) {
            for(int col = m-1; col >= 0; col--) {
                if(row == n-1 && col == m-1)
                    continue;
                for(int sum = 0; sum < k; sum++) {
                    int ans = 0;
                    int newSum = (sum + grid[row][col]) % k;
                    if(row + 1 < n) {
                        ans = (ans + dp[row+1][col][newSum]) % M;
                    }
                    if(col + 1 < m) {
                        ans = (ans + dp[row][col+1][newSum]) % M;
                    }
                    dp[row][col][sum] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};