class Solution {
public:
    long long countCommas(long long n) {
        if(n <= 999) return 0;
        if(n < 1e6) return n - 999;
        if(n < 1e9) {
            long long a = n - 1e6 + 1;
            long long ans = a + (n - 999);
            return ans;
        }
        if(n < 1e12){
            long long a = n - 1e9 + 1;
            long long b = n - 1e6 + 1;
            long long ans = a + b + (n-999);
            return ans;
        }
        if(n <= 1e15){
            long long a = n - 1e12 + 1;
            long long b = n - 1e9 + 1;
            long long c = n - 1e6 + 1;
            long long d = n - 999;
            long long ans = a + b + c + d;
            if( n == 1e15) return ans + 1;
            return ans;
        }
        return -1;
    }
};