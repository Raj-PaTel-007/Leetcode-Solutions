class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        unordered_set<int>st1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int xr = nums[i]^nums[j];
                st1.insert(xr);
            }
        }
        unordered_set<int>ans;
        for(auto it1 : st){
            for(auto it2 : st1){
                int xr = it1^it2;
                ans.insert(xr);
            }
        }
        return ans.size();
    }
};