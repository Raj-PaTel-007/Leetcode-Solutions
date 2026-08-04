class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
 unordered_set<int> s(nums.begin(), nums.end());
    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
       vector<int> res;
    for (int i = low; i <= high; ++i)
        if (!s.count(i)) res.push_back(i);
    return res;
    }
};