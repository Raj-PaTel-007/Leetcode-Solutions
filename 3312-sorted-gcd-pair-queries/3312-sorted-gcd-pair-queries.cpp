#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n  = nums.size();
        int mx = INT_MIN;
        for(auto it : nums) mx = max(mx,it);
        unordered_map<int,int>mp;
        for(auto it : nums)mp[it]++;
        vector<ll>div(mx + 1,0);
        for(int i = 1; i<= mx ;i++){
            int num = i;
            while(num <= mx){
                div[i] += mp[num];
                num += i;
            }
        }
        vector<ll>pairs(mx+1,0);
        for(int i=1 ;i <= mx;i++){
            pairs[i] = 1LL*(div[i]*(div[i]-1))/2;
        }
        for(int i=mx;i>=1;i--){
            int num = 2*i;
            while(num <= mx){
                pairs[i] -= pairs[num];
                num += i;
            }
        }
        vector<ll>pref(mx+1,0);
        pref[0] = 0;
        for(int i=1;i<=mx;i++) pref[i] = pairs[i] + pref[i-1];
        vector<int>ans;
        for(auto it : queries){
            long long num = it;
            ll idx = lower_bound(pref.begin(),pref.end(),it+ 1) - pref.begin();
            ans.push_back(idx); 
        }
        return ans;
    }
};