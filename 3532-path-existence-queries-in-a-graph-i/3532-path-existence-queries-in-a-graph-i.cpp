class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        int cnt = 0;
        mp[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                mp[i] = cnt;
            }
            else{
                cnt++;
                mp[i] = cnt;
            }
        }
        vector<bool>ans;
        for(auto it : queries){
            if(mp[it[0]] == mp[it[1]]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};