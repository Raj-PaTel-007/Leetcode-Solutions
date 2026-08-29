class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        ans.reserve(n * m);

        int r = 0, c = 0;
        bool up = true;

        while ((int)ans.size() < n * m) {
            ans.push_back(mat[r][c]);

            if (up) {
                if (c == m - 1) {
                    r++;
                    up = false;
                } else if (r == 0) {
                    c++;
                    up = false;
                } else {
                    r--;
                    c++;
                }
            } else {
                if (r == n - 1) {
                    c++;
                    up = true;
                } else if (c == 0) {
                    r++;
                    up = true;
                } else {
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};