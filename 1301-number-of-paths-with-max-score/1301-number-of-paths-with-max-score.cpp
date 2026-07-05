#define ll long long int
ll M = 1e9 + 7;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& arr) {
        ll n = arr.size();
        ll m = arr[0].size();
        arr[n-1][m-1] = '0';
        vector<vector<pair<ll,ll>>>dp(n+1,vector<pair<ll,ll>>(m+1,{-1e18,0}));
        for(int i = 1 ;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i == 1 && j == 1){
                    dp[i][j] = {0,1};
                    continue;
                }
                 ll a = dp[i-1][j].first;
                 ll b = dp[i][j-1].first;
                 ll c= dp[i-1][j-1].first;
                 ll mx = max(a,max(b,c));
                 mx = max(mx,dp[i][j].first);
                 if(mx == -1e18){
                    dp[i][j] = {-1e18,0};
                    continue;
                 }
                 ll p = 0;
                 if(a == mx){
                    p += dp[i-1][j].second;
                    p = p %M;
                 }
                 if(b == mx){
                    p += dp[i][j-1].second;
                    p = p %M;
                 }
                 if(c == mx){
                     p += dp[i-1][j-1].second;
                     p = p %M;
                 }
                 if(arr[i-1][j-1] == 'X'){
                     dp[i][j] = {-1e18,0};
                 }
                 else{
                    dp[i][j] = {(mx + (arr[i-1][j-1] - '0')) % M , p %M};
                 }
            }
        }
        if(dp[n][m].first == -1e18) return {0,0};
        vector<int>ans;
        ans.push_back(dp[n][m].first);
        ans.push_back(dp[n][m].second);
        return ans;
    }
};