class Solution {
public:

    int fun(int i,int j,string &s,string &p,vector<vector<int>>&dp)
{
    int n=s.size();
    int m=p.size();

    if(i==n){
        while(j<m){
            if(p[j]!='*') return 0;
            j++;
        }
        return 1;
    }

    if(j==m) return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(p[j]=='?')
        return dp[i][j]=fun(i+1,j+1,s,p,dp);

    if(p[j]=='*')
        return dp[i][j]=fun(i+1,j,s,p,dp) || fun(i,j+1,s,p,dp);

    if(s[i]!=p[j])
        return dp[i][j]=0;

    return dp[i][j]=fun(i+1,j+1,s,p,dp);
}

    bool isMatch(string s, string p) {
        if(s == ""){
            int cnt  = 0;
            for(auto it : p) if(it == '*')cnt++;
            return cnt == p.size();
        }
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,s,p,dp);
    }
};