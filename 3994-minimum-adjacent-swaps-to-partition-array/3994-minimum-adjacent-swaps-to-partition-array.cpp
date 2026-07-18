#define ll long long
ll M = 1e9 + 7;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        ll n = nums.size();
        ll c1 = 0;
        ll c2 =0;
        ll c3 =0;
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < a){
                ans = (ans + c2 + c3)%M;
                c1++;
            }
            else if(nums[i] >= a && nums[i] <= b){
                ans = (ans + c3) % M;
                c2++;
            }
            else{
                c3++;
            }
        }
        return ans;
    }
};