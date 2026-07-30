class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int cnt = 1;
        int raj = 0;
        int n = word.size();
        for(int i=0;i<n;i++){
            ans += cnt;
            raj++;
            if(raj == 8){
                cnt++;
                raj = 0;
            }
        }
        return ans;
    }
};