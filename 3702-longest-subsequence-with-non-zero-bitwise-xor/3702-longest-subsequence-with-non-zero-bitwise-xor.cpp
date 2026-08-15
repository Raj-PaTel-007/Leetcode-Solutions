class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            xr = xr^nums[i];
            if(nums[i] == 0) cnt++;
        }
        if(xr == 0 ) {
            if(cnt == n) return 0;
            else return n-1;
        }
        else return n;
    }
};