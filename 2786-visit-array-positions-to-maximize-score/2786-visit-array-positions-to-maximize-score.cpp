class Solution {
public:

    long long fun(int idx,vector<int>&nums,int x,int last_parity,vector<vector<long long>>&dp){
       int n = nums.size();
       if(idx == n)return 0;
       if(dp[idx][last_parity] != -1)return dp[idx][last_parity];
       int curr_parity = nums[idx] % 2;
       long long nontake = fun(idx + 1,nums,x,last_parity,dp);
       long long take = -1e18;
       if(curr_parity == last_parity) take = nums[idx] + fun(idx+1,nums,x,last_parity,dp);
       else take = nums[idx] - x + fun(idx+1,nums,x,curr_parity,dp);
       return dp[idx][last_parity] = max(take,nontake);
    }

    long long maxScore(vector<int>& nums, int x) {
        long long n = nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return nums[0] + fun(1,nums,x,nums[0]%2,dp);
    }
};