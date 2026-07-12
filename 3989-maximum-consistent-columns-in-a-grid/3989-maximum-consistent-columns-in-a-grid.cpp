class Solution {
public:

    int fun(int idx,int lastcol,vector<vector<int>>&grid,int limit,vector<vector<int>>&dp){
        int m = grid[0].size();
        int n = grid.size();
        if(idx == m) return 0;
        if(dp[idx][lastcol+1] != -1) return dp[idx][lastcol+1];
        int ans1 = fun(idx+1,lastcol,grid,limit,dp);
        bool flag = true;
        int ans2 = 0;
        if(lastcol == -1) ans2 = 1 + fun(idx+1,idx,grid,limit,dp);
        else{
            for(int i=0;i<n;i++){
                if(abs(grid[i][lastcol] - grid[i][idx]) > limit) flag = false;
            }
            if(flag) ans2 = 1 + fun(idx+1,idx,grid,limit,dp);
        }
        return dp[idx][lastcol+1] = max(ans1,ans2);
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(0,-1,grid,limit,dp);
    }
};