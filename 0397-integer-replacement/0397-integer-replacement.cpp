class Solution {
public:
    int integerReplacement(int nn) {
        long long n = nn;
        int ans = 0;
        while(n > 1) {
            if(n == 3) n--;
            else if(n % 2 == 0) n >>= 1;
            else if(n % 4 == 1) n--;
            else n++;
            ans++;
        }
        return ans;
    }
};