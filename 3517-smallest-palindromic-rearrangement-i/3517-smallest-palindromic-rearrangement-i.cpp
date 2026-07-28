class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> h(26,0);

        for(int i=0;i<n;i++){
            h[s[i]-'a']++;
        }

        string ans = "";
        bool odd = false;
        char ch;

        for(int i=0;i<26;i++){
            int cnt = h[i]/2;

            while(cnt--){
                ans += char('a'+i);
            }

            if(h[i]&1){
                odd = true;
                ch = char('a'+i);
            }
        }

        string t = ans;
        reverse(ans.begin(),ans.end());

        if(odd)
            return t + ch + ans;

        return t + ans;
    }
};