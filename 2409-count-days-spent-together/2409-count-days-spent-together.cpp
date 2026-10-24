class Solution {
public:
    int countDaysTogether(string a, string b, string c, string d) {
        string s = max(a, c);
        string e = min(b, d);

        if (s > e) return 0;

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto f = [&](string x) {
            int m = stoi(x.substr(0, 2));
            int d = stoi(x.substr(3, 2));
            int t = d;

            for (int i = 0; i < m - 1; i++)
                t += days[i];

            return t;
        };

        return f(e) - f(s) + 1;
    }
};