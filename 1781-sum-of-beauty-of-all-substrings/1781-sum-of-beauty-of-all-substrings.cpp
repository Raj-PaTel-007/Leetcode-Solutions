class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j = i;j<n;j++){
                mp[s[j]]++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for(auto it : mp){
                    mx = max(mx,it.second);
                    mn = min(mn,it.second);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};