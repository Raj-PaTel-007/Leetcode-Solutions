class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int ts = 0;
       for(auto it : nums) ts += it;
       int ans1 = INT_MAX;
       int ans2 = INT_MIN;
       int sum1 = 0;
       int sum2 = 0;
       int n = nums.size();
       for(int i=0;i<n;i++){
          sum1 += nums[i];
          sum2 += nums[i];
          if(sum1 < ans1){
             ans1 = sum1;
          }
          if(sum1 > 0) sum1 = 0;
          if(sum2 > ans2){
            ans2 = sum2;
          }
          if(sum2 <= 0) sum2 = 0;
       }
       if(ts == ans1) return ans2;
       int ans = max(ans2,ts-ans1);
       return ans;
    }
};