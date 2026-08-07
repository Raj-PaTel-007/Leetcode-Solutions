class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int k) {
        int n = arr.size();
        int mx = *max_element(arr.begin(),arr.end());
        vector<bool>ans(n,true);
        for(int i=0;i<n;i++){
            if(arr[i] + k < mx) ans[i] = false;
        }
        return ans;
    }
};