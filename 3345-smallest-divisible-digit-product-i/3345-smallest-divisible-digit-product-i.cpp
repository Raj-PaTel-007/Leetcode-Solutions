class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true) {
            int copy = n;
            int temp = 1;
            while(copy) {
                temp *= copy % 10;
                copy /= 10;
            }
            if (temp % t) {
                n++;
            } else {
                return n;
            }
        }
        return 0;
    }
};