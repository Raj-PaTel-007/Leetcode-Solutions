class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans="";
        if(k>1) {
            sort(s.begin(),s.end());
            return s;
        }
        ans=s;
        int n=s.size();
        for(int i=0;i<n;i++) {
            string p=s.substr(i)+s.substr(0,i);
            ans=min(ans,p);
        }
        return ans;
    }
};