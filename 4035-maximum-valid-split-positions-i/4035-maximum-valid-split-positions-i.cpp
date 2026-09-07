class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
       int n = nums.size();
       if(n == 1) return 0;
       int ans = 0;
       for(int i=0;i<n;i++){
         int cnt = 0;
         vector<int>temp;
         for(int j=0;j<n;j++){
            if(i != j)temp.push_back(nums[j]);
         }
         vector<int>pre(n-1);
         vector<int>suf(n-1);
         pre[0] = temp[0];
         for(int j = 1;j<temp.size();j++) pre[j] = __gcd(pre[j-1],temp[j]);
         suf[n-2] = temp[n-2];
         for(int j=n-3;j>=0;j--) suf[j] = __gcd(suf[j+1],temp[j]);
         for(int j=0;j<temp.size()-1;j++){
            if(pre[j] == suf[j+1]) cnt++;
         }
         ans = max(ans,cnt);
       }
       int cnt = 0;
        vector<int>pre(n);
         vector<int>suf(n);
         pre[0] = nums[0];
         for(int j = 1;j<n;j++) pre[j] = __gcd(pre[j-1],nums[j]);
         suf[n-1] = nums[n-1];
         for(int j=n-2;j>=0;j--) suf[j] = __gcd(suf[j+1],nums[j]);
         for(int j=0;j<nums.size() -1;j++){
            if(pre[j] == suf[j+1]) cnt++;
         }
         ans = max(ans,cnt);
       return ans;
    }
};