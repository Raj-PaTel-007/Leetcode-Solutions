class Solution {
public:

    bool ispal(string s){
        int i  = 0;
        int j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        while(i + k - 1 < n){
            string s1 = s.substr(i,k);
            string s2 = s.substr(i,k+1);
            if(ispal(s1)){
                ans++;
                i += k;
            }
            else if(ispal(s2)){
                ans++;
                i += k+1;
            }
            else i++;
        }
        return ans;
    }
};