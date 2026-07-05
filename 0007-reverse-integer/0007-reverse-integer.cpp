class Solution {
public:
   long long int reverse(long long int x) {
        int flag=0;
        if(x<0) {
            flag=1;
            x=-x;
    }
       long long int num=0;
        while(x>0){
            int p=x%10;
            num=num*10 +p;
            x=x/10;
        }
       long long k= 1LL << 31;
       if(k-1<num) return 0;
       if(flag==1 && k<num)return 0;
        return flag==1?(-num):num;
    }
};