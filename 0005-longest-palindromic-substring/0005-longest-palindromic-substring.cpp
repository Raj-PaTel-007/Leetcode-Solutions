class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();
       vector<vector<bool>>dp(n,vector<bool>(n,false));
       for(int i=0;i<n;i++) dp[i][i] = true;
       string ans = s.substr(0,1);
       for(int len=2;len<=n;len++){
          for(int i=0;i + len<=n;i++){
            if(len == 2 && s[i] == s[i+1]){
                dp[i][i+1] = true;
            }
            else if(s[i] == s[i+len - 1]  && dp[i+1][i+len-2]) dp[i][i+len-1] = true;
            if(dp[i][i+len-1]) ans = s.substr(i,len);
          }
       }
       return ans;
    }
};