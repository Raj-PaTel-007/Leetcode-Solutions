class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums)mp[it]++;
        int n = nums.size();
        int idx = (n)/2;
        if(mp[nums[idx]] == 1) return true;
        return false;
    }
};