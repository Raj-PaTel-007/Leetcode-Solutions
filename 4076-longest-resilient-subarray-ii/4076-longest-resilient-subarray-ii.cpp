class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
         int n = nums.size();
        int ans = 1;
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            temp[i] = nums[i] % k;
        }
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(temp[i] == temp[i-1])cnt++;
            else {
                if((temp[i-1]*(cnt - 1)) % k == 0) ans = max(ans,cnt);
                cnt = 1;
            }
            if((temp[i-1]*(cnt - 1)) % k == 0) ans = max(ans,cnt);
        }
        if((temp[n-1]*(cnt - 1)) % k == 0) ans = max(ans,cnt);
        return ans;
    }
};