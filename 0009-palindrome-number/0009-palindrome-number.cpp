class Solution {
public:
    bool isPalindrome(long long int x) {
        long long num = x;
        long long int revnum = 0;
        while (num > 0) {
            int k = num % 10;
            revnum = revnum* 10 + k;
             num = num / 10;
        }
        if (revnum == x) {
            return true;
        } else {
            return false;
        }
    }
};