#define ll long long int
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        ll n = s.size();
        ll c0 = 0;
        ll c1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') c0++;
            else c1++;
        }
    ll C = c1;
       vector<ll>pre(n+1);
       for(int i=0;i<n;i++){
           pre[i+1] = pre[i] + (s[i] == '1'); 
       }
        vector<bool>ans;
        for(auto it : strs){
            string t = it;
            ll o = 0;
            ll q = 0;
            vector<int>p;
            for(int i=0;i<n;i++){
                if(t[i] == '1')o++;
                else if(t[i] == '?'){
                    q++;
                    p.push_back(i);
                }
            }
            int raj = c1 - o;
            if(raj < 0 || raj > q){
                ans.push_back(false);
                continue;
            }
            string a = t;
            for(int i=0;i<q;i++){
                a[p[i]] = (i >= q - raj) ?'1' :'0'; 
            }
            bool ok = true;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(a[i] == '1') cnt++;
                if(cnt > pre[i+1]){
                    ok =false;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};