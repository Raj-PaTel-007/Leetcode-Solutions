#define ll long long
class Solution {
public:

    ll fun(ll mid,ll m,ll n){
        ll cnt = 0;
        for(int i=1;i<=m;i++){
            ll a = mid/i;
            a = min(a,n);
            cnt += a;
        }
        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
       ll l = 1;
       ll r = m*n;
       int ans = -1;
       while(l <= r){
           ll mid = (l + r)/2;
           ll cnt1 = fun(mid-1,m,n);
           ll cnt2 = fun(mid,m,n);
           if(cnt1 < k && cnt2 >= k){
             ans = mid;
             break;
           }
           if(cnt2 >= k) r = mid - 1;
           else l = mid + 1;
       }
        return ans;
    }
};