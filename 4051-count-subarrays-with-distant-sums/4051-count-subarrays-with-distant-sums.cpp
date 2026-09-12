#define ll long long int
class Solution {
public:
    ll fun(vector<ll>&pref,ll l,ll r,ll a,ll b){
        if(l >= r) return 0;
        ll mid  = (l+r)/2;
        ll ans = 0;
        ans += fun(pref,l,mid,a,b);
        ans += fun(pref,mid+1,r,a,b);
        ll p = mid + 1;
        ll q = mid + 1;
        for(int i=l;i<=mid;i++){
            while(p <= r && pref[p] - pref[i] < a) p++;
            while(q <= r && pref[q] - pref[i] <= b) q++;
            ans += q - p;
        }
        vector<ll>temp;
        ll i = l;
        ll j = mid + 1;
        while(i <= mid && j <= r){
            if(pref[i] <= pref[j]) temp.push_back(pref[i++]);
            else temp.push_back(pref[j++]);
        }
        while(i <= mid) temp.push_back(pref[i++]);
        while(j <= r) temp.push_back(pref[j++]);
        for(int i=l;i<=r;i++){
            pref[i] = temp[i-l];
        }
        return ans;
    }
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        ll n = nums.size();
        if(k == 0) return (n*(n+1)/2);
        vector<ll>pref(n+1,0);
        for(ll i=0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }
        ll a = goal - k + 1;
        ll b = goal + k - 1;
        ll ans = fun(pref,0,n,a,b);
        ll tt = n*(n+1)/2;
        return tt - ans;
    }
};