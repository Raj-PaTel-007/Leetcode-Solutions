class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int a = 0;
        int b = 0;
        for(int i=0;i<m;i++){
            int c = a;
            int d = b;
            if(a < n && s[a] == t[i]) c++;
            if(b < n && s[b] == t[i]) d++;
            if(a < n ) d = max(d,a+1);
            a = c;
            b = d;
        }
        return a == n || b == n;
    }
};