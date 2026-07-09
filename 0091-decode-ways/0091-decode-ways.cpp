class Solution {
public:
    vector<int>dp;
    int fun(int idx , string s){
       int n = s.size();
       if(idx == n) return 1;
       if(dp[idx] != -1) return dp[idx];
       int ans = 0;
       for(int i=idx;i<min(n,idx + 2);i++){
         string temp =  s.substr(idx,i-idx+1);
         int num = stoi(temp);
         if(num > 0 && num < 27){
            if(temp.size() == 2 && num/10 == 0) continue;
            ans += fun(i+1,s);
         }
       }
       return dp[idx] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n);
        for(int i=0;i<n;i++)dp[i] = -1;
       return fun(0,s);
    }
};