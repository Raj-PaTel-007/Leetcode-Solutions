#define ll long long int
class Solution {
public:
    ll fun(ll first,ll last,vector<int>&nums,ll last_player,vector<vector<vector<ll>>>&dp){
        if(last < first) return 0;
        ll ans = 0;
        if(dp[first][last][last_player-1] != -1e18) return dp[first][last][last_player-1];
        if(last_player == 1){
            ll l = nums[first] - fun(first+1,last,nums,2,dp);
            ll r = nums[last] - fun(first,last-1,nums,2,dp);
            ans = max(l,r);
        }
        else{
            ll l = nums[first] - fun(first + 1,last,nums,1,dp);
            ll r = nums[last] - fun(first,last-1,nums,1,dp);
            ans = max(l,r);
        }
        return dp[first][last][last_player-1] = ans;
    }

    bool stoneGame(vector<int>& nums) {
        ll sum = 0;
        ll n = nums.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1e18)));
        ll ans = fun(0,n-1,nums,2,dp);
        if(ans < 0) return false;
        return true;
    }
};