class Solution {
public:
    bool winnerSquareGame(int n) {
       vector<bool>dp(n+1,false);
       for(int i=1;i<=n;i++){
         int sq = sqrt(i);
         for(int j=1;j<=sq;j++){
            if(!dp[i - j*j]) dp[i] = true;
         }
       }
       return dp[n];
    }
};