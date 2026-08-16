class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        int n = stones.size();
        for(auto it : stones){
            if(it % 3 == 0) c0++;
            if(it % 3 == 1) c1++;
            if(it % 3 == 2) c2++;
        }
      bool ans1 = false;
      int a = c0;
      int b = c1;
      int c = c2;
      if(c1 > 0){
         ans1 = true;
         c1--;
         int cnt = 1 + c0;
         int sum = 1;
         while(c1 > 0 || c2 > 0){
            if(sum == 1){
                if(c1 > 0){
                    sum = 2;
                    c1--;
                }
                else {
                    if(cnt % 2 == 0 && c2) ans1 = false;
                    break;
                }
            }
            else{
                if(c2 > 0){
                    sum = 1;
                    c2--;
                }
                else{
                    if(cnt % 2 == 0 && c1)ans1 = false;
                    break;
                }
            }
            cnt++;
         }
         if(c1 == 0 && c2 == 0) ans1 = false;
      }
         c0= a;
         c1 = b;
         c2 = c;
          bool ans2 = false;
      if(c2 > 0){
         ans2 = true;
         c2--;
         int cnt = 1 + c0;
         int sum = 2;
         while(c1 > 0 || c2 > 0){
            if(sum == 1){
                if(c1 > 0){
                    sum = 2;
                    c1--;
                }
                else {
                    if(cnt%2 == 0 && c2) ans2 = false;
                    break;
                }
            }
            else{
                if(c2 > 0){
                    sum = 1;
                    c2--;
                }
                else{
                    if(cnt % 2 == 0 && c1)ans2 = false;
                    break;
                }
            }
            cnt++;
         }
         if(c1 == 0 && c2 == 0) ans2 = false;
      }
      return ans1 || ans2;
    }
};