class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string str1 = to_string(low);
        int sizek = str1.size();
        string str2 = to_string(high);
        int maxsize = str2.size();
        int firstelement = str1[0] - '0';
        for (int sz = sizek; sz <= maxsize; sz++) {
    for (int i = firstelement; i <= 10 - sz; i++) {

        long long num = 0;
        int val = i;

        for (int cnt = 0; cnt < sz; cnt++) {
            num = num * 10 + val;
            val++;
        }

        if (num > high)
            break;

        if (num >= low)
            ans.push_back(num);
    }

    firstelement = 1;
}
        return ans;
    }
};