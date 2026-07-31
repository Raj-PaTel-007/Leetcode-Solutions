#define ll long long int
class Solution {
public:

    ll fun(ll idx,vector<int>&arr,int last,vector<vector<ll>>&dp){
        int n  = arr.size();
        if(idx == n) return 0;
        ll ans = -1e9;
        if(dp[idx][last] != -1e18) return dp[idx][last];
        if(idx  < n){
            ll t = arr[idx] - fun(idx + 1,arr,last ^ 1,dp);
            ans = max(ans,t);
        }
         if(idx + 1 < n){
            ll t = arr[idx] + arr[idx + 1] - fun(idx + 2,arr,last ^ 1,dp);
            ans = max(ans,t);
        }
        if(idx + 2 < n){
            ll t = arr[idx] + arr[idx + 1] + arr[idx+2] - fun(idx +3,arr,last^1,dp);
            ans = max(ans,t);
        }
        return dp[idx][last] = ans;
    }

    string stoneGameIII(vector<int>& arr) {
        ll n = arr.size();
        vector<vector<ll>>dp(n,vector<ll>(2,-1e18));
        ll ans = fun(0,arr,0,dp);
        if(ans == 0) return "Tie";
        else if(ans > 0) return "Alice";
        return "Bob";
    }
};