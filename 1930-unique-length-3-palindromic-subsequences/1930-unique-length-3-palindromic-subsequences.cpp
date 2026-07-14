class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>>temp(26,vector<int>(26,0));
        unordered_map<char,int>mp1;
        for(auto it : s)mp1[it]++;
        unordered_map<char,int>mp2;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(auto it : mp2){
                 if(it.first == s[i] && mp2[it.first] == 1) continue;
                if(mp1[it.first] > 0){
                    if(temp[s[i]-'a'][it.first-'a'] == 0){
                        ans++;
                        temp[s[i]-'a'][it.first-'a'] = 1;
                    }
                   
                }
            }
            mp1[s[i]]--;
            mp2[s[i]]++;
        }
        return ans;
    }
};