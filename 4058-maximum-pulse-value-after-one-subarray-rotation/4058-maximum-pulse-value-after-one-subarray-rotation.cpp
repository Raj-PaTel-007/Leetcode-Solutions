#define ll long long int
class Solution {
public:
long long int minEvenKadane(vector<int>& a) {
    long long int odd = LLONG_MAX;
    long long int even = LLONG_MAX;
    long long int ans = LLONG_MAX;

    for(int x : a) {
        long long int newOdd = x;
        long long int newEven = LLONG_MAX;

        if(even != LLONG_MAX)
            newOdd = min(newOdd, even + x);

        if(odd != LLONG_MAX)
            newEven = odd + x;

        odd = newOdd;
        even = newEven;

        ans = min(ans, even);
    }

    return ans;
}
    long long maxValue(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        ll sum = 0;
        for(int i=0;i<nums.size();i++){
            if(i&1) nums[i] = -nums[i];
            sum += nums[i];
        }
        ll k = minEvenKadane(nums);
        return max(sum,sum-2*k);
    }
};