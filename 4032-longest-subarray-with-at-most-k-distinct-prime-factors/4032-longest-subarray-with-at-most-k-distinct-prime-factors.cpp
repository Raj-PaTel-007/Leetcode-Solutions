class Solution {
public:
    int longestSubarray(vector<int>& a, int k) {
        int n = a.size();
        int m = *max_element(a.begin(), a.end());

        vector<int> s(m + 1);

        for (int i = 0; i <= m; i++)
            s[i] = i;

        for (int i = 2; i * i <= m; i++) {
            if (s[i] == i) {
                for (int j = i * i; j <= m; j += i) {
                    if (s[j] == j)
                        s[j] = i;
                }
            }
        }

        unordered_map<int, int> c;
        int l = 0, r = 0, ans = 0;

        while (r < n) {
            int x = a[r];

            while (x > 1) {
                int p = s[x];

                c[p]++;

                while (x % p == 0)
                    x /= p;
            }

            while (c.size() > k) {
                x = a[l];

                while (x > 1) {
                    int p = s[x];

                    c[p]--;

                    if (c[p] == 0)
                        c.erase(p);

                    while (x % p == 0)
                        x /= p;
                }

                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};