class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int cnt = 0;
        int st = -1;
        int end = -1;
        for(auto it : intervals){
            int left = it[0];
            int right = it[1];
            if(st <= left && right <= end){}
            else{
                cnt++;
                if(st == -1 && end == -1){
                    st = left;
                } 
                end = right;
            }
        }
        return cnt;
    }
};