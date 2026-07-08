#define ll long long int
ll M = 1e9 + 7;
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll>pre(n);
        pre[0] = s[0] - '0';
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + (s[i] - '0');
        }
        vector<ll>num(n);
        vector<ll>digit(n);
        num[0] = s[0] - '0';
        digit[0] = s[0] - '0' > 0 ? 1 : 0;
        for(int i=1;i<n;i++){
           int k = num.size();
           int diff = s[i] - '0';
           if(diff!= 0 ){
             digit[i] = 1 + digit[i-1];
             num[i] = (num[i-1]*10  + diff) % M;
           }
           else{
            digit[i] = digit[i-1];
            num[i] = num[i-1];
           }
        }
        vector<ll>power(n+1);
        power[0] = 1;
        for(int i=1;i<=n;i++){
            power[i] =(power[i-1]*10)% M;
        }
        vector<int>ans;
        for(auto it : queries){
           int l = it[0];
           int r = it[1];
           ll d = (digit[r] -( l > 0 ? digit[l-1] : 0));
          ll p = ((l > 0 ? num[l-1] : 0) * power[d]) % M;
           ll a =( num[r] - p + M) % M;
           ll f = pre[r] - (l >0 ? pre[l-1] :0);
           ll o =( a*f) % M;
           ans.push_back(int(o));
        }
        return ans;
    }
};