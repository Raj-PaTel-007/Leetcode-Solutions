class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        unordered_map<char,int>mp;
        for(auto it : s)mp[it]++;
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans  = n;
        while(j < n){
            mp[s[j]]--;
            while(i<=j && mp[s[j]] < k){
                mp[s[i]]++;
                i++;
            }
            ans = min(ans,n-j+i-1);
            j++;
        }
        return ans;
    }
};