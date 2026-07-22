class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0;
        int n = s.size();
        int cnt = 0;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '1')cnt++;
        }
        ans = max(ans,cnt);
        bool f1 = false;
        bool f2 = false;
        bool f3 = false;
        cnt = 0;
        int raj = 0;
        int cnt0 = 0;
        int ans0 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if(f1 && !f2){
                    f2 = true;
                }
                else if(f1 && f2 && f3){
                    if(cnt0 >= ans0){
                        ans0 = cnt0;
                        ans = cnt;
                        idx = i - 1;
                    }
                    cnt = raj;
                    cnt0 = raj;
                    raj = 0;
                    f1 = true;
                    f2 = true;
                    f3 = false;
                }
                cnt++;
            }
            else{
                if(!f1){
                    f1 = true;
                }
                else if(f1 && f2){
                    f3 = true;
                }
                if(f1 && f2){
                    raj++;
                }
                cnt++;
                cnt0++;
            }
        }
        if(f1 && f2 && f3){
            if(cnt0 > ans0){
                ans = cnt;
                idx = n-1;
            }
        }
        int p = ans;
        while(p-- && idx >= 0){
            s[idx] = '1';
            idx--;
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1')cnt++;
        }
        return max(ans,cnt);
    }
};