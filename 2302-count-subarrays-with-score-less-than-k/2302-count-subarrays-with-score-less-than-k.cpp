#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        ll i = 0;
        ll j = 0;
        ll sum = 0;
        ll ans = 0;
        while(j < n){
            sum += nums[j];
            while((j - i + 1)*sum >= k){
                sum -= nums[i];
                i++;
            }
          ans += j - i + 1;
          j++;
        }
        return ans;
    }
};