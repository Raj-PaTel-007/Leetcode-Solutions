class Solution {
public:
    int numTilings(int n) {
        vector<long>dp(n+1,0);
        long M = 1e9 + 7;
        dp[1] = 1;
        if(n == 1)return 1;
        if(n == 2) return 2;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4;i<=n;i++){
            dp[i] =(2*dp[i-1] + dp[i-3]) % M;
        }
        return dp[n];
    }
};