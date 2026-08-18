class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size()) return *max_element(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums)mp[it]++;
        if(k == 1){
            int ans = -1;
            for(auto it : mp){
                if(it.second == 1) ans = max(ans,it.first);
            }
            return ans;
        }
        mp[nums[0]]--;
        mp[nums[n-1]]--;
        if(nums[0] == nums[n-1]){
            if(k == n) return nums[0];
            return -1;
        }
        if(mp[nums[0]] > 0 && mp[nums[n-1]] > 0) return -1;
        if(mp[nums[0]] == 0 && mp[nums[n-1]] == 0) return max(nums[0],nums[n-1]);
        if(mp[nums[0]])return nums[n-1];
        return nums[0];
    }
};