class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(m));;
        dp[0][0].insert(grid[0][0]);
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(i){
                   for(auto &it : dp[i-1][j]){
                       dp[i][j].insert(it^grid[i][j]);
                   }
               }
               if(j){
                   for(auto &it:dp[i][j-1]){
                       dp[i][j].insert(it^grid[i][j]);
                   }
               }
           }
       }
        int ans = 1e7;
        for(auto &it:dp[n-1][m-1]) ans = min(ans,it);
        return ans;
    }
};