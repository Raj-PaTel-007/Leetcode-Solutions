class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        map<pair<int, int>, int> mp;

        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];

            if (a == b) continue;

            int x = min(a, b);
            int y = max(a, b);

            mp[{x, y}]++;
        }

        if (mp.empty()) {
            int ans = 0;
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1]) ans++;
            }
            return ans;
        }

        pair<int, int> bestPair;
        int maxi = 0;

        for (auto it : mp) {
            if (it.second > maxi) {
                maxi = it.second;
                bestPair = it.first;
            }
        }

        int x = bestPair.first;
        int y = bestPair.second;

        vector<int> temp = nums;
        for (int i = 0; i < n; i++) {
            if (temp[i] == x) {
                temp[i] = y;
            }
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (temp[i] == temp[i + 1]) {
                ans++;
            }
        }

        return ans;
    }
};