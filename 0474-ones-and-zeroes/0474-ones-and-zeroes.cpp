class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        int sz = str.size();
        vector<int>z(sz);
        vector<int>o(sz);
        for(int i=0;i<sz;i++){
            string s = str[i];
            int c0 = 0;
            int c1 = 0;
            for(auto it : s) {
                if(it == '0') c0++;
                else c1++;
            }
            z[i] = c0;
            o[i] = c1;
        }
        vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=1;i<=sz;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int nontake = dp[i-1][j][k];
                    int take = INT_MIN;
                    if(j >= z[i-1] && k >= o[i-1]) take =  1 + dp[i-1][j-z[i-1]][k-o[i-1]];
                    dp[i][j][k] = max(take,nontake);
                }
            }
        }
        return dp[sz][m][n];
    }
};