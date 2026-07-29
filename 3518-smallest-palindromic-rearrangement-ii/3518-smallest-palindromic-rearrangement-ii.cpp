#define ll long long
ll M = 4e8;
class Solution {
public:
    ll C(ll n, ll r){
        ll t = 1;
        if (n - r < r) r = n - r;
        for (int i = 1; i <= r; i++) {
            t *= (n + 1 - i);
            t /= i;
            if (t >= M) return M;
        }
        return t;
    }

    ll cnt(array<int,26>& a) {
        int n = accumulate(a.begin(), a.end(), 0);
        ll ans = 1;
        for (int x : a) {
            if (!x) continue;
            ans *= C(n, x);
            n -= x;
            if (ans >= M) return M;
        }
        return ans;
    }

    bool build(span<char> s, int k) {
        array<int,26> a{};
        for (char c : s) a[c - 'a']++;
        if (cnt(a) <= k) return false;
        ll n = accumulate(a.begin(), a.end(), 0LL);
        for (char& c : s) {
            ll cur = cnt(a);
            for (int i = 0; i < 26; i++) {
                if (!a[i]) continue;
                ll x = (cur == M) ? M : (cur * 1LL * a[i]) / n;
                if (x > k) {
                    c = 'a' + i;
                    a[i]--;
                    break;
                }

                k -= x;
            }

            n--;
        }

        return true;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size() / 2;

        if (!build({s.begin(), s.begin() + n}, k - 1))
            return "";

        copy(s.begin(), s.begin() + n, s.rbegin());

        return s;
    }
};