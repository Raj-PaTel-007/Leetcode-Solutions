#define ll long long int

class Solution {
public:

    ll fun(int i, int j, int k, int last, vector<vector<int>>& grid,
           vector<vector<vector<vector<ll>>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j][k][last] != -1)
            return dp[i][j][k][last];

        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};

        ll ans = 1e14;

        for(int l = 0; l < 4; l++) {
            int nx = i + dx[l];
            int ny = j + dy[l];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(l == last || last == 4) {
                ans = min(ans, grid[i][j] +
                    fun(nx, ny, k, l, grid, dp));
            }
            else if(l != last && k > 0) {
                ans = min(ans, grid[i][j] +
                    fun(nx, ny, k-1, l, grid, dp));
            }
        }

        return dp[i][j][k][last] = ans;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<vector<ll>>>> dp(
            n,
            vector<vector<vector<ll>>>(
                m,
                vector<vector<ll>>(k+1, vector<ll>(5, -1))
            )
        );

        ll ans = fun(0, 0, k, 4, grid, dp);

        if(ans >= 1e14) return -1;

        return ans;
    }
};