class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();

        int c0 = 0, c1 = 0;

        for (char c : s) {
            if (c == '0')
                c0++;
            else
                c1++;
        }

        if (abs(c0 - c1) > 1)
            return -1;

        int ans = 1e5;
        if (c0 >= c1) {
            int wrong = 0;

            for (int i = 0; i < n; i++) {
                char need = (i % 2 == 0 ? '0' : '1');

                if (s[i] != need)
                    wrong++;
            }

            ans = min(ans, wrong / 2);
        }
        if (c1 >= c0) {
            int wrong = 0;

            for (int i = 0; i < n; i++) {
                char need = (i % 2 == 0 ? '1' : '0');

                if (s[i] != need)
                    wrong++;
            }

            ans = min(ans, wrong / 2);
        }

        return ans;
    }
};