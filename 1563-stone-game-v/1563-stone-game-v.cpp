class Solution {
public:

    vector<int>pre;
    int fun(int l,int r,vector<int>&nums,vector<vector<int>>&dp){
        if(r == l) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i=l;i<=r;i++){
            int prev = l > 0 ? pre[l-1] : 0;
            int ls = pre[i] - prev;
            int rs = pre[r] - pre[i];
            if(ls < rs){
                ans = max(ans,ls + fun(l,i,nums,dp));
            }
            else if(ls > rs){
                 ans = max(ans,rs + fun(i+1,r,nums,dp));
            }
            else{
               ans = max(ans,ls + fun(l,i,nums,dp));
               ans = max(ans,rs + fun(i+1,r,nums,dp));
            }
        }
        return dp[l][r] = ans;
     }

    int stoneGameV(vector<int>&arr) {
        int n = arr.size();
        pre.resize(n);
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + arr[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(0,n-1,arr,dp);
    }
};