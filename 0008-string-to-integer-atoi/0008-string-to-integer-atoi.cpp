class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long int ans = 0;
        bool flag = false;
        while(i<n && (s[i] == ' '))i++;
        if(s[i] == '+') i++;
        else if(s[i] == '-') {
            flag = true;
            i++;
        }
        int cnt = 0;
        while( i<n && (s[i] == '0')) i++;
        while( i<n && ((s[i] >= '0' && s[i] <= '9')) && cnt < 12){
            ans = ans*10 + (s[i] - '0');
            i++;
            cnt++;
        }
       
         if((ans >= (1LL<<31))  && flag) return -1LL *( 1LL<<31);
          else if( ans >= ((1LL << 31) - 1) && (!flag)) return( 1LL << 31) - 1;
        if(flag) return -1*ans;
        return ans;
    }
};