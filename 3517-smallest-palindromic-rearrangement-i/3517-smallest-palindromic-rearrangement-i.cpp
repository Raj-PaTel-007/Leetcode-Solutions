class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>hash(26,0);
        for(int i=0;i<n;i++){
            hash[s[i] - 'a']++;
        }
        string ans = "";
        bool odd = false;
        char ch;
        for(int i=0;i<26;i++){
            int num = hash[i];
            if(num & 1){
                odd = true;
                ch  = char('a' + i);
                int cnt = (num/2);
                while(cnt--){
                    ans += char('a' + i);
                }
            }
            else{
                 int cnt = (num/2);
                while(cnt--){
                    ans += char('a' + i);
                }
            }
        }
        string temp = ans;
        reverse(ans.begin(),ans.end());
        if(odd) return temp + ch + ans;
       return temp + ans;
    }
};