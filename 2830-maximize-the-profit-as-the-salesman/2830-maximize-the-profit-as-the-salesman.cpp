class Solution {
public:

    vector<int> dp;

    int fun(int idx,int n,vector<vector<int>>&o){
        int a = o.size();
        if(idx == a) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = fun(idx+1,n,o);

        int l = idx + 1, r = a;

        while(l < r){
            int mid = l + (r-l)/2;

            if(o[mid][0] > o[idx][1])
                r = mid;
            else
                l = mid + 1;
        }

        ans = max(ans,o[idx][2] + fun(l,n,o));

        return dp[idx] = ans;
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        dp.assign(offers.size(),-1);

        return fun(0,n,offers);
    }
};