class Solution {
public:

    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[n-1][m-1] = min(0,arr[n-1][m-1]);
        for(int i= n- 1 ; i>=0 ;i--){
            for(int j= m-1;j>=0;j--){
                if(i == n-1 && j == m-1) continue;
               int ans1 = INT_MIN;
               int ans2 = INT_MIN;
                if(i + 1 < n){
                    ans1 = arr[i][j] + dp[i+1][j];
                }
                if(j+1 < m){
                    ans2 = arr[i][j] + dp[i][j+1];
                }
                if(ans1 < 0 && ans2 < 0) dp[i][j] = max(ans1,ans2);
                else dp[i][j] = 0;
            }
        }
        return 1 + -1*dp[0][0];
    }
};