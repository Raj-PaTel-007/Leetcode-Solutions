class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it : arr)mp[it]++;
        int ans = 0;
        for(auto it : mp){
            int a = it.first;
            int b = it.second;
            int cnt = b/(a+1);
            if(b % (a+1) == 0) ans += cnt*(a+1);
            else ans += (cnt +1)*(a+1); 
        }
        return ans;
    }
};