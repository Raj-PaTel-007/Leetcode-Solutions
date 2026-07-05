class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            int num = nums[i];
            string str = to_string(num);
            sort(str.begin(),str.end());
            int diff = str[str.size()-1] - str[0];
            if(diff > mx){
                mx = diff;
                ans = nums[i];
            }
            else if(diff == mx){
                ans += nums[i];
            }
        }
        return ans;
    }
};