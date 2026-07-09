class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = arr[0] - bottom;
        int mn  = bottom;

        for(int i=0;i<n;i++){
            if(arr[i] > top) break;
            ans = max(ans,arr[i]-mn-1);
            mn = max(mn,arr[i]);
        }
        ans = max(ans,top-arr[n-1]);
        return max(ans,0);
    }
};