class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = INT_MIN;
        int n = s.size();
        for(char ch = 'A' ; ch <= 'Z' ; ch++){
            int i = 0;
            int j = 0;
            int cnt = 0;
            while(j < n){
                if(s[j] != ch) cnt++;
                while(cnt > k){
                    if(s[i] != ch) cnt--;
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans ;
    }
};