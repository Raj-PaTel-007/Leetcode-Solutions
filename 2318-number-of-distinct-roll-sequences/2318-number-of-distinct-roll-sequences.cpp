#define ll long long
ll M = 1e9 + 7;
class Solution {
public:
    ll fun(int idx,int n,int last1,int last2,vector<vector<vector<int>>>&dp){
        if(idx == n) return 1;
        if(dp[idx][last1][last2] != -1) return dp[idx][last1][last2];
        ll ans = 0;
        for(int i=1;i<=6;i++){
            if(idx == 0){
                ans = (ans + fun(idx+1,n,i,i,dp))%M;
            }
            else if(idx == 1){
                if(i!=last1 && __gcd(i,last1) == 1){
                    ans = (ans + fun(idx+1,n,i,last1,dp)) % M;
                }
            }
            else if(i != last1 && i != last2 && __gcd(last1,i) == 1){
                ans = (ans + fun(idx+1,n,i,last1,dp)) % M;
            }
        }
        return dp[idx][last1][last2] = ans;
    }
    int distinctSequences(int n) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(7,vector<int>(7,-1)));
        return fun(0,n,0,0,dp);
    }
};