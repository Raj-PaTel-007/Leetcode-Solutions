#define ll __int128
long long M = 1e9 + 7;
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        ll rem = k;
        ll cnt = 0;
        for(int i=0;i<n;i++){
            if(rem >= nums[i]){
                rem = rem-nums[i];
            }
            else{
                ll d = nums[i] - rem;
                ll p = (d + k - 1)/k;
                rem = rem + p*k;
                rem = rem - nums[i];
                ll prev = cnt*(cnt+1)/2 % M; 
                cnt += p;
                ans = (ans + ((cnt*(cnt+1)/2))%M - prev + M)%M;
            }
        }
        return ans % M;
    }
};