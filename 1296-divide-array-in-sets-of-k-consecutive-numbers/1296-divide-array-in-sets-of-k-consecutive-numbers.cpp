class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(auto it : nums) mp[it]++;
        while(mp.size() > 0){
            auto[a,b] = *mp.begin();
            int num = a;
            int cnt = 0;
            while(cnt < k){
                if(mp.find(num) != mp.end()){
                    mp[num]--;
                    if(mp[num] == 0) mp.erase(num);
                    num++;
                    cnt++;
                }
                else return false;
            }
        }
        return true;
    }
};