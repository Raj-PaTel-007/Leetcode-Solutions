#define ll long long int
class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<ll>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        queue<ll>q;
        q.push(0);
        ll h = 1;
        while(!q.empty()){
            ll sz = q.size();
            ll p = sz;
            while(p--){
                ll t = q.front();
                q.pop();
                for(auto it : adj[t]){
                    q.push(it);
                }
            }
            h++;
        }
        h--;
        q.push(0);
        ll cnt = 1;
        ll ans = 0;
        while(!q.empty()){
            ll sz = q.size();
            ll p = sz;
            while(p--){
                ll t = q.front();
                q.pop();
                ans += nums[t]*(h - cnt + 1);
                for(auto it : adj[t]){
                    q.push(it);
                }
            }
            cnt++;
    }
    return ans;
    }
};