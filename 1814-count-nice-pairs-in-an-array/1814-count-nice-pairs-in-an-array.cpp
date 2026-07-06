class Solution {
public:
    int countNicePairs(vector<int>& nums) {
         int n = nums.size();
         long long M = 1e9 + 7;
         unordered_map<long long,long long>mp;
         int ans = 0;
         for(int i=0;i<n;i++){
            string p = to_string(nums[i]);
            reverse(p.begin(),p.end());
            long long k = stoll(p);
            long long num = nums[i] - k;
            ans = (ans + mp[num]) % M;
            mp[num]++;
         }
         return ans;
    }
};