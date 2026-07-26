class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        int a = nums[0];
        int b = nums[1];
        int c = nums[n-1];
        int d = nums[n-2];
        int e = nums[n-3];
        int m1 = a*b*c;
        int m2 = c*d*e;
        ans = max(m1,m2);
        return ans;
    }
};