class Solution {
public:
    int consecutiveNumbersSum(int n) {
        if(n == 1)return 1;
        int ans = 0;
        int l = sqrt(n) + 1;
        for(int i=2;i<n;i++){
            if(i*(i+1)/2 > n)break;
            if(i & 1){
                if(n % i == 0){
                    ans++;
                }
            }
            else{
                if((n % i) == (i/2)){
                    ans++;
                }
            }
            cout << i << " " << ans << endl;
        }
        return ans + 1 ;
    }
};