class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int>dq;
        for(auto it : arr) dq.push_back(it);
        int n = arr.size();
        if(k >= n) return *max_element(arr.begin(),arr.end());
        int cnt = 0;
        while(1){
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if(a > b){
                cnt++;
                dq.push_back(b);
                dq.push_front(a);
            }
            else{
                cnt = 1;
                 dq.push_back(a);
                 dq.push_front(b);
            }
            if(cnt == k) return dq.front();
        }
        return -1;
    }
};