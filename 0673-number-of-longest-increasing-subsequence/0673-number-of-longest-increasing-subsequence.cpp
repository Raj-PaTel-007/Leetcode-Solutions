class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int mx = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        mx = max(mx,dp[i]);
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j] + 1){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == mx) ans += cnt[i];
        }
        return ans;
    }
};