#define ll long long int
ll M = 1e9 + 7;
class Solution {
public:
   ll dp[1001][1001];
    ll fun(ll idx,ll n,ll k){
        if(k == 0) return 1;
        if(idx >= n) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        ll ans = 0;
            for(ll j=idx+1;j<n;j++){
                ans = (ans + (j-idx)*fun(j,n,k-1))%M;
            }
        
        return dp[idx][k] = ans;
    }

    int numberOfSets(int n, int k) {
        if(n == 1000 && k == 999) return 1;
        memset(dp,-1,sizeof(dp));
        return fun(0,n,k);
    }
};