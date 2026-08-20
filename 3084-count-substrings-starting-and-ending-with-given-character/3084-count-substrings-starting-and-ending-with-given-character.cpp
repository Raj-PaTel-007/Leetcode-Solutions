#define ll long long int
class Solution {
public:
    long long countSubstrings(string s, char c) {
        ll n = s.size();
        ll ans = 0;
        ll cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == c){
                cnt++;
            }
        }
        return cnt*(cnt+1)/2;
    }
};