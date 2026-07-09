class Solution {
public:

    bool is_vowel(char ch){
        if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pre(n,0);
        int sz = words[0].size();
        if(is_vowel(words[0][0]) && is_vowel(words[0][sz-1])) pre[0] = 1;
        for(int i=1;i<n;i++){
            int sz = words[i].size();
            if(is_vowel(words[i][0]) && is_vowel(words[i][sz-1])) pre[i] = pre[i-1] + 1;
            else pre[i] = pre[i-1];
        }
        vector<int>ans;
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            if(l == 0) ans.push_back(pre[r]);
            else ans.push_back(pre[r] - pre[l-1]);
        }
        return ans;
    }
};