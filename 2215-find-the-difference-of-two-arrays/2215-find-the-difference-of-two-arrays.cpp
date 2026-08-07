class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> n1, n2;
        for (int n : nums1) {
            n1.insert(n);
        }
        for (int n : nums2) {
            n2.insert(n);
        }
        for (int x : n1) {
            if (!n2.count(x)) { 
                ans[0].push_back(x);
            }
        }

        for (int x : n2) {
            if (!n1.count(x)) { 
                ans[1].push_back(x);
            }
        }

        return ans;
    }
};