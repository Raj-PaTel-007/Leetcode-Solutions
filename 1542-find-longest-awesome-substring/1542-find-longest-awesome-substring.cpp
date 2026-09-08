class Solution {
public:
    int longestAwesome(string s) {
        int ans = 1;
        int n = s.size();
        unordered_map<int,int>mp;
        int xr = 0;
        for(int i=0;i<n;i++){
            int num = s[i] - '0';
            xr = xr ^ (1LL << num);
            if(xr == 0) ans = max(ans,i+1);
            if(mp.find(xr) == mp.end()) mp[xr] = i;
            else ans = max(ans,i - mp[xr]);
            for(int j=0;j<31;j++){
                int nxr = xr ^ (1LL << j);
                if(nxr == 0) ans = max(ans,i+1);
                if(mp.find(nxr) != mp.end()) ans = max(ans,i - mp[nxr]);
            }
        }
        return ans;
    }
};