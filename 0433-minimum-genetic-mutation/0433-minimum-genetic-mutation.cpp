class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st;
        for(auto it : bank)st.insert(it);
        queue<string>q;
        q.push(start);
        unordered_map<string,bool>vis;
        vis[start] = true;
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                string temp = q.front();
                q.pop();
                if(temp == end) return cnt;
                int n = temp.size();
                for(int i=0;i<n;i++){
                    char prev = temp[i];
                    for(char ch : string("ACGT")){
                        if(ch != prev){
                            temp[i] = ch;
                            if(st.find(temp) != st.end() && vis.find(temp) == vis.end()){
                                q.push(temp);
                                vis[temp] = true;
                            }
                        }
                    }
                    temp[i] = prev;
                }
            }
            cnt++;
        }
        return -1;
    }
};