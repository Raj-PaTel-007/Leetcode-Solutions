int M = 1e9 + 7;
class Solution {
public:
    int dp[301][301][32];
    int fun(int i,int j,int k,vector<vector<int>>&grid,int last){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1){
            if((last ^ grid[i][j]) == k) return 1;
            return 0;
        }
        if(dp[i][j][last] != -1) return dp[i][j][last];
        int ans = 0;
        if(i+1 < n)ans = (ans + fun(i+1,j,k,grid,last^grid[i][j])) % M;
        if(j + 1 < m) ans = (ans + fun(i,j+1,k,grid,last^grid[i][j]))%M;
        return dp[i][j][last] = ans;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,k,grid,0);
    }
};