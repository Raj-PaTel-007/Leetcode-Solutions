class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        vector<int>ans(2,0);
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            else if(sum > target) j--;
            else i++;
        }
        return ans;
    }
};