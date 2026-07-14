#define ll long long
ll M = 1e9 + 7;
class Solution {
public:
    int fun(int idx,int g1,int g2,vector<int>&nums,int dp[201][201][201]){
        int n = nums.size();
        if(idx == n){
            if (g1 != 0 && g2 != 0 && g1 == g2)
                return 1;
            return 0;
        }
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];
        int ans = 0;
        ans = (ans + fun(idx+1,g1,g2,nums,dp)) % M;
        ans = (ans + fun(idx+1,__gcd(nums[idx],g1),g2,nums,dp))%M;
        ans = (ans + fun(idx+1,g1,__gcd(nums[idx],g2),nums,dp))%M;
        return dp[idx][g1][g2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        int dp[201][201][201];
        for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++){
                for(int k=0;k<=200;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return fun(0,0,0,nums,dp)%M;
    }
};