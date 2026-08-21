class Solution {
public:
    int dp[1001][1001];
    int fun(int idx,int cnt,vector<int>&arr){
        int n = arr.size();
        if(idx == n) return 0;
        if(dp[idx][cnt] != -1)return dp[idx][cnt];
        int ans = INT_MIN;
        ans = max(ans,fun(idx+1,cnt,arr));
        ans = max(ans,arr[idx]*cnt + fun(idx+1,cnt+1,arr));
        return dp[idx][cnt] =  ans;
    }

    int maxSatisfaction(vector<int>&arr){
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return fun(0,1,arr);
    }
};