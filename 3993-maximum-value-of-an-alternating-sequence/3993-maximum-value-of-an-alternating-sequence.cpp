#define ll long long int
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        ll k = n-1;
        ll a = (k+1)/2LL;
        if(a == 0) return s;
        return 1LL*s + a*m - (a-1); 
    }
};