class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int ans = 1;
        int l = arr[0][0];
        int r = arr[0][1];
        int n = arr.size();
        for(int i=0;i<n;i++){
            int a = arr[i][0];
            int b = arr[i][1];
            if(a <= r){
                l = max(a,l);
                r = min(b,r);
            }
            else{
                ans++;
                l = a;
                r = b;
            }
        }
        return ans;
    }
};