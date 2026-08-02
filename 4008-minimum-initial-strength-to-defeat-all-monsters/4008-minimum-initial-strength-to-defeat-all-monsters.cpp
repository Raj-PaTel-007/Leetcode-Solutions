#define ll long long int
class Solution {
public:

    bool check(vector<int>&arr,vector<ll>&v,ll mid){
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(mid + v[i] < arr[i]) return false;
            mid -= arr[i];
            if(mid < 0) mid = 0;
        }
        return true;
    }

    long long minInitialStrength(vector<int>& arr, vector<vector<int>>& b) {
        int n = arr.size();
        vector<ll>v(n,0);
        for(auto it : b){
            int x = it[0];
            int y = it[1];
            int z = it[2];
            v[x] += z;
            if(y + 1 < n) v[y+1] -= z;
        }
        for(int i=1;i<n;i++){
            v[i] += v[i-1];
        }
        ll l = 0;
        ll r = 0;
        for(int i=0;i<n;i++) r += arr[i];
        ll ans = 0;
        while(l <= r){
            ll mid = l + (r-l)/2;
            cout << mid << endl;
            if(check(arr,v,mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
     }
};