class Solution {
public:
    void fun(vector<int>arr,int idx, int n,vector<int>nums,vector<vector<int>>&ans){
        if(idx == n){
            ans.push_back(arr);
            return;
        }
        fun(arr,idx+1,n,nums,ans);
        arr.push_back(nums[idx]);
        fun(arr,idx+1,n,nums,ans);
        // arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        int n = nums.size();
        fun(arr,0,n,nums,ans);
        return ans;
    }
};