class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<int,int> mp;
            vector<int> v;
            int bad = 0;

            for(int j = i; j < n; j++) {
                int x = nums[j];

                if(mp.find(x) == mp.end()) {
                    v.push_back(x);
                    mp[x] = 0;
                }

                mp[x]++;

                int k = v.size();
                bool ok = true;

                for(int t = 0; t < k; t++) {
                    if(mp[v[t]] != t + 1) {
                        ok = false;
                        break;
                    }
                }

                if(ok) ans++;
            }
        }

        return ans;
    }
};