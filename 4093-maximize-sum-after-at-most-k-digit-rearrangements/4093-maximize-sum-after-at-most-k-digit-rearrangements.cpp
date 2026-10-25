#define ll long long int
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<pair<ll,ll>>vp(n);
        for(int i=0;i<n;i++){
            string str = to_string(nums[i]);
            sort(str.rbegin(),str.rend());
            ll num = stoll(str);
            ll diff = num - nums[i];
            vp[i] = {diff,i};
        }
        sort(vp.rbegin(),vp.rend());
        vector<bool>vis(n,false);
        ll ans = 0;
        for(int i=0;i<k;i++){
            ll idx = vp[i].second;
            string str = to_string(nums[idx]);
            sort(str.rbegin(),str.rend());
            ll num = stoll(str);
            ans += num;
            vis[idx] = true;
        }
      for(int i=0;i<n;i++){
         if(!vis[i]) ans += nums[i];
      }
      return ans;
    }
};