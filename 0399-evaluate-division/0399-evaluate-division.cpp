class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>&arr, vector<double>&values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string,vector<pair<string,double>>>adj;
        unordered_set<string>st;
        vector<double>ans;
        for(int i=0;i<n;i++){
            adj[arr[i][0]].push_back({arr[i][1], 1.0 * values[i]});;
            adj[arr[i][1]].push_back({arr[i][0], 1.0 / values[i]});;
            st.insert(arr[i][0]);
            st.insert(arr[i][1]);
        }
        for(auto it : queries){
            string num1 = it[0];
            string num2 = it[1];
            if(num1 == num2 && st.find(num1) != st.end()){
                ans.push_back(1.000000);
                continue;
            }
            if(st.find(num1) == st.end() || st.find(num2) == st.end()){
                ans.push_back(-1.000000);
                continue;
            }
            queue<pair<string,double>>q;
            q.push({num1,1.0000});
            unordered_map<string,bool>vis;
            vis[num1] = true;
            bool flag = false;
            while(!q.empty()){
               pair<string,double>temp = q.front();
               q.pop();
               string t1 = temp.first;
               double t2 = temp.second;
               if( t1 == num2){
                 ans.push_back(t2);
                 flag = true;
                   break;
               }
               for(auto it : adj[t1]){
                   pair<string,double>p1 = it;
                   if(vis.find(p1.first) == vis.end()){
                    q.push({p1.first,t2*p1.second});
                    vis[p1.first] = true;
                   }
               }  
            }
            if(!flag)  ans.push_back(-1.000000);
        }
        return ans;
    }
};