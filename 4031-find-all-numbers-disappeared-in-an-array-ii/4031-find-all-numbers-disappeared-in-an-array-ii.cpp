class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int l, int r) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int j = 0;
        int n = nums.size();
        bool flag = false;
        while(j < n && nums[j] <= l)j++;
        if(j == n){
            int k1 = nums[j-1] == l ? l + 1 : l;
            int k2 = nums[j-1] == r ? r-1 : r;
            if(k1<=k2)ans.push_back({k1,k2});
            return ans;
        }
        if(nums[j] >= r && j > 0){
            int k1 =  nums[j-1] ;
            if(k1 == l) k1++;
            k1 = max(l,k1);
            int k2;
            if(nums[j] == r) k2 = r-1;
            else k2 = r;
            if(k1 <= k2 )ans.push_back({k1,k2});
            return ans;
        }
        for(int i=j;i<n;i++){
            if(i == j){
                int k1 = l;
                if(i > 0 && nums[i-1] == l) k1 = l+1;
                  int k2;
                k2 = min(nums[i] - 1,nums[i] == r ? r-1:r);
                cout << k2 << endl;
            if(k1 <= k2 )ans.push_back({k1,k2});
               if(nums[i] >= r )break;
            }
            else{
                int a = nums[i-1] + 1 ;
                int b = min(nums[i] - 1 , r);
                if(a <= b) ans.push_back({a,b});
                if(b == r){
                    flag = true;
                    break;
                }
            }
             if(nums[i] > r) break;
        }
        if(!flag && nums[n-1] + 1 <= r) ans.push_back({nums[n-1] + 1,r});
        return ans;
    }
};