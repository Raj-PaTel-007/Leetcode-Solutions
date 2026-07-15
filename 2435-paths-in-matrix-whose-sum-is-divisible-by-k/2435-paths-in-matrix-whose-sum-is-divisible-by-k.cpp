#define ll long long int
ll M = 1e9 + 7;

int fun(int row,int col,vector<vector<int>>&grid,int k,int sum, vector<vector<vector<int>>>&dp){
    int n = grid.size();
    int m = grid[0].size();
    if(row == n-1 && col == m-1){
        if((sum+grid[row][col])% k == 0) return 1;
        return 0;
    }
    if(dp[row][col][sum] != -1) return dp[row][col][sum];
    int ans = 0;
    if(row + 1 < n){
        ans = (ans + fun(row + 1,col,grid,k,(sum + grid[row][col])%k,dp))%M;
    }
    if(col + 1  < m){
         ans = (ans + fun(row ,col + 1,grid,k,(sum + grid[row][col])%k,dp))%M;
    }
    return dp[row][col][sum] = ans;
}

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,
      vector<vector<int>>(m,
        vector<int>(k, -1)));
        return fun(0,0,grid,k,0,dp);
    }
};