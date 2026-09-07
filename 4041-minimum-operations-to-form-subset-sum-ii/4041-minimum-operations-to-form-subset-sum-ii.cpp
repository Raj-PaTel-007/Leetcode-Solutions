
class Solution {
public:
    int fun(int idx,vector<int>&nums,int s,int sum,vector<vector<int>>&dp){
        int n = nums.size();
        if(idx == n){
            if(sum == s) return 0;
            else return 1e6;
        }
         if(sum == s) return 0;
         if(sum > s) return 1e6;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int ans = 1e6;
        ans = min(ans,fun(idx+1,nums,s,sum,dp));
        int val = nums[idx];
        int cnt = 0;
        while((sum +( val * (1LL << (cnt)))) <= s){
            int oo = val * (1LL << cnt);
            ans = min(ans, cnt  + fun(idx+1,nums,s, sum + oo,dp));
            if(oo & 1){
                int pk = oo - 1;
                int raj = 0;
                if(pk != 0){
                while(sum + pk*(1 << raj) <= s){
                    ans = min(ans,cnt + 2 + raj+fun(idx+1,nums,s,sum + pk*(1LL << raj),dp));
                    raj++;
                }
                }
            }
            cnt++;
        }
        val = nums[idx];
        cnt = 0;
        while((val/(1LL << cnt)) > 0 ){
            int oo = val/(1LL << cnt);
            ans = min(ans,cnt+fun(idx+1,nums,s,sum + val/(1LL << cnt),dp));
            if(oo & 1) {
                int pk = oo - 1;
           if(pk != 0){
                int raj = 0;
                while(sum + pk*(1LL << raj) <= s){
                    ans = min(ans,cnt + 2 + raj+fun(idx+1,nums,s,sum + pk*(1LL << raj),dp));
                    raj++;
                }
            }
            }
            cnt++;
        }
        
        return dp[idx][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        vector<vector<int>>dp(nums.size() + 1,vector<int>(1e4,-1));
        int a =  fun(0,nums,sum,0,dp);
        if(a >= 1e6) return -1;
        return a;
    }
};