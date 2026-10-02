class Solution {
public:
   
        void fun(string s, int open, int close, int n, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            fun(s + '(', open + 1, close, n, ans);
        }

        if (close < open) {
            fun(s + ')', open, close + 1, n, ans);
        }
    

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fun("",0,0,n,ans);
        return ans;
    }
};