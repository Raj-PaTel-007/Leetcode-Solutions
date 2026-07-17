class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int n=j.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(j[i]);
        }
        int ans = 0 ;
        int m = s.size();
        for(int i = 0 ; i< m ;i++){
            if(st.find(s[i]) != st.end()) ans++;
        }
        return ans;
    }
};