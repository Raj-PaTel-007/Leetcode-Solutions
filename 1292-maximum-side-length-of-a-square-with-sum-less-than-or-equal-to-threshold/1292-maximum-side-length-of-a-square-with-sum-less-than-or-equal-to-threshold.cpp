class Solution {
public:

   bool check(int sz,vector<vector<int>>&dp,int th){
    int n = dp.size();
    int m = dp[0].size();
    for(int i=sz-1;i<n;i++){
        for(int j=sz-1;j<m;j++){
            int sum = dp[i][j];
            if(i-sz >= 0) sum -= dp[i-sz][j];
            if(j-sz >= 0) sum -= dp[i][j-sz];
            if(i-sz >= 0 && j-sz >= 0) sum += dp[i-sz][j-sz];
            if(sum <= th) return true;
        }
    }
    return false;
}

    int maxSideLength(vector<vector<int>>& mat, int th) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i -1 >= 0) dp[i][j] +=dp[i-1][j];
                if(j-1 >= 0) dp[i][j] += dp[i][j-1];
                dp[i][j] += mat[i][j];
                if(i-1 >= 0 && j-1 >=0){
                    dp[i][j] -= dp[i-1][j-1];
                }
            }
        }
        int lo = 1;
        int hi = min(n,m);
        int ans = 0;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(check(mid,dp,th)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};