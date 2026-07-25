class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(),str.end());
        int k = str.size();
        int a=str[k-1] - '0';
        int b=str[k-2] - '0';
        return a*b;
    }
};