class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
         unordered_set<int> st1, st2;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> curr;
            curr.insert(nums[i]);
            for (int val : st2) {
                curr.insert(val | nums[i]);
            }
            for (auto x : st2) {
                st1.insert(x);
            }
            st2 = curr;
        }
        for (auto x : st2) st1.insert(x);
        return st1.size();
    }
};