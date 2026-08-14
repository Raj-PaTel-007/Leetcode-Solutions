class Solution {
public:
    double dp[101][101];
    double fun(int idx,int k,vector<int>&pre,vector<int>&nums){
        int n = nums.size();
        if(k == 1){
            if(idx == 0) return 1.0*pre[n-1] / (n-idx);
            return 1.0*(pre[n-1] - pre[idx-1])/(n-idx);
        }
        if(dp[idx][k] != -2.0000) return dp[idx][k];
        double ans = -1.000000;
        for(int i=idx;i<n-k+1;i++){
            double avg;
            if(idx == 0) avg = 1.0*(pre[i])/(i+1);
            else avg =( 1.0*(pre[i] - pre[idx-1]))/(i - idx + 1);
            ans = max(ans,avg + fun(i+1,k-1,pre,nums));
        }
        return dp[idx][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n);
        fill(&dp[0][0], &dp[0][0] + 101*101, -2.0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
      return fun(0,k,pre,nums);
    }
};