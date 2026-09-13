class Solution {
public:
    int dp[1LL << 21];
    int fun(int num,int mx,int d,int sum){
        if(sum >= d) return false;
        if(dp[num] != -1)return dp[num];
          for(int i=1;i<=mx;i++){
            if(num & (1LL << i)) continue;
            if(!fun(num | (1LL << i) , mx,d,sum + i)) return dp[num] = true;
       }
       return dp[num] = false;
    }

    bool canIWin(int mx, int d) {
        if(d == 0) return true;
        memset(dp,-1,sizeof(dp));
        if(mx * (mx + 1) / 2 < d) return false;
        return fun(0,mx,d,0);
    }
};