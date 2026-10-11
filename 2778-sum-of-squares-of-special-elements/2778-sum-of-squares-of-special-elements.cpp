class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        for(int i=0;i<nums.size();i++){
            if(nums.size() % (i+1)) continue;
            ans += nums[i]*nums[i];
        }
        return ans;
    }
};