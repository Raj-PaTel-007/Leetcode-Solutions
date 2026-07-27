class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            auto it = lower_bound(temp.begin(),temp.end(),nums[i]);
            if(it == temp.end())temp.push_back(nums[i]);
            else{
                int idx = it - temp.begin();
                temp[idx] = nums[i];
            }
            if(temp.size() == 3) return true;
        }
        return false;
    }
};