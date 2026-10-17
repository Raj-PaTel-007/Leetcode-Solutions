class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
        temp = nums;
        sort(temp.begin(),temp.end(),[&](int a,int b){
            int sum1 = 0;
            int k1 = a;
            while(k1 > 0){
                sum1 += k1 % 10;
                k1 = k1/10;
            }
            int sum2 = 0;
            int k2 = b;
            while(k2 > 0){
                sum2 += (k2%10);
                k2 = k2/10;
            }
            if(sum1 == sum2) return a < b;
            return sum1 < sum2;
        });
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int curr = temp[i];
            int idx = mp[curr];
            if(i != idx){
                mp[nums[i]] = idx;
                mp[nums[idx]] = i;
                swap(nums[i],nums[idx]);
                ans++;
            }
        }
        return ans;
    }
};