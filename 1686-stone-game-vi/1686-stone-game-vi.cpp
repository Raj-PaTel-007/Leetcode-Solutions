class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<vector<int>>pq;
        int n = a.size();
        for(int i=0;i<n;i++){
            pq.push({a[i] + b[i] ,i});
        }
        int cnt = 0;
        int idx = 0;
        while(!pq.empty()){
            vector<int>temp = pq.top();
            pq.pop();
            if(idx & 1) cnt -= b[temp[1]];
            else cnt += a[temp[1]];
            idx++;
        }
        if(cnt > 0) return 1;
        else if(cnt == 0) return 0;
        return -1;
    }
};