#define ll long long int
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        ll i = 0;
        ll j = 0;
        while(j < n){
            while(j+1<n &&  nums[j] != nums[j+1])j++;
            int len = j - i + 1;
            ans +=1LL*((1LL*len)*(len+1))/2;
            i = j+1;
            j++;
        }
            return ans;
    }
};