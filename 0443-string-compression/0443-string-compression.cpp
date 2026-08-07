class Solution {
public:
    int compress(vector<char>& arr) {
        int n = arr.size();
        int cnt = 1;
        int ans = 0;
        int i = 1;
        char ch  = arr[0];
        while(i<n){
            if(arr[i] == arr[i-1]) cnt++;
            else{
                arr[ans] = ch;
                ans++;
                if(cnt > 1){
                string temp = to_string(cnt);
                for(auto it : temp){
                    arr[ans] = it;
                    ans++;
                }
                }
                 ch = arr[i];
                cnt = 1;
            }
            i++;
        }
        arr[ans] = ch;
                ans++;
                if(cnt > 1){
                string temp = to_string(cnt);
                for(auto it : temp){
                    arr[ans] = it;
                    ans++;
                }
        }
         return ans;
    }
};