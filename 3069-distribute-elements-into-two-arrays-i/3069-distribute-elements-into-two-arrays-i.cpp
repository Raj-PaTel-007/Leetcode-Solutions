class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int s1 = arr1.size();
            int s2 = arr2.size();
            if(arr1[s1-1] > arr2[s2-1]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        vector<int>ans;
        for(auto it : arr1) ans.push_back(it);
        for(auto it : arr2) ans.push_back(it);
        return ans;
    }
};