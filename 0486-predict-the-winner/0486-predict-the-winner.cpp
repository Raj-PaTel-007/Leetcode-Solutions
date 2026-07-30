#define ll long long int
class Solution {
public:
    ll fun(ll first,ll last,vector<int>&nums,ll last_player){
        if(last < first) return 0;
        ll ans = 0;
        if(last_player == 1){
            ll l = nums[first] - fun(first+1,last,nums,2);
            ll r = nums[last] - fun(first,last-1,nums,2);
            ans = max(l,r);
        }
        else{
            ll l = nums[first] - fun(first + 1,last,nums,1);
            ll r = nums[last] - fun(first,last-1,nums,1);
            ans = max(l,r);
        }
        return ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        ll sum = 0;
        ll n = nums.size();
        for(auto it : nums) sum += it;
        ll ans = fun(0,n-1,nums,2);
        if(ans < 0) return false;
        return true;
    }
};