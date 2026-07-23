class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return n;
        int cnt = 0;
        while(n > 0){
            n = n/2;
            cnt++;
        }
        int ans = (1LL << cnt);
        return ans;
    }
};