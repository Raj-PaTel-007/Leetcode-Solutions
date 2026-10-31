 int mod=1e9+7;

class Solution {
public:
    int n,m;
    int dp[502][502][2];
    int f(int i,int j,int d,vector<vector<int>>& grid)
    {
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m || i<0 || j<0) return 0;
        if(dp[i][j][d]!=-1) return dp[i][j][d];
        if(grid[i][j]==1)
        {
            int right=0,down=0;
            if(d==1){
                down=f(i+1,j,0,grid);
            }
            else if(d==0){
                right=f(i,j+1,1,grid);
            }
            return dp[i][j][d]=(right+down)%mod;
        }
        int right=f(i,j+1,1,grid);
        int down=f(i+1,j,0,grid);
        return dp[i][j][d]=(right+down)%mod;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,grid);
    }
};