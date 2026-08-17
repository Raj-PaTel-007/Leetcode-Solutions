class Solution {
public:

    vector<vector<int>> dp;
    bool fun(int idx,int last,vector<int>&stones){
        int n = stones.size();
        if(idx == n-1)return true;
        bool ans = false;
        if(dp[idx][last] != -1)return dp[idx][last];
        for(int k = last - 1; k <= last + 1; k++){
            if (k <= 0) continue;
            int target = stones[idx] + k;
            auto it = lower_bound(stones.begin(), stones.end(), target);
            if (it != stones.end() && *it == target) {
                int i = it - stones.begin();
                if (fun(i, k, stones)) {
                    ans = true;
                    break;
                }
            }
        }
        return dp[idx][last] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        dp.assign(n, vector<int>(n+1,-1));
        return fun(1, 1, stones) && stones[1] == 1;
    }
};