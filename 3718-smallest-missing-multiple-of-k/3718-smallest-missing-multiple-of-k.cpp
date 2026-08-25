class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = -1;
        int p = k;
        while(1){
            if(st.find(p) == st.end()) return p;
            p+=k;
        }
        return 0;
    }
};