#define ll long long int
class Solution {
public:

    ll fun(ll idx,ll last_el,vector<int>&arr1,vector<int>&arr2,map<pair<ll,ll>,ll>&mp){
        int n = arr1.size();
        if(idx == n)return 0;
        ll nt = 1e8;
        if(mp.find({idx,last_el}) != mp.end()) return mp[{idx,last_el}];
        if(arr1[idx] > last_el){
            nt = fun(idx + 1,arr1[idx],arr1,arr2,mp);
        }
        ll t = 1e8;
        int j = upper_bound(arr2.begin(),arr2.end(),last_el) - arr2.begin();
        for(int i=j;i<arr2.size();i++){
            t = min(t , 1 + fun(idx + 1,arr2[i],arr1,arr2,mp));
            break;
        }
        return mp[{idx,last_el}] = min(t,nt);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<ll,ll>,ll> mp;
        ll res=fun(0,-1,arr1,arr2,mp);
        return (res>=1e8?-1:res);
    }
};