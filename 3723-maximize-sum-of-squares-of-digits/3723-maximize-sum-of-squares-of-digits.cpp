class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        int p = sum/9;
        int k = sum%9;
        string ans = "";
        int cnt = 0;
        for(int i=0;i<p;i++){
            ans += '9';
            cnt++;
        }
        if(cnt<num) {
            ans+=to_string(k);
            cnt++;
        }
        while(cnt<num){
            ans += '0';
            cnt++;
        }
        return ans;
    }
};