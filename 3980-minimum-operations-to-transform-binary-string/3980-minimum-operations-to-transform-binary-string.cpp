class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1) {
           if(s1[0] == '1' && s2[0] == '0') return -1;
           if(s1 == s2) return 0;
            return 1;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                if(s1[i] == '0'){
                    s1[i] = '1';
                    ans++;
                }
                else{
                    if(i+1 < n && s1[i+1] == '1'){
                        ans += 1;
                        s1[i] = '0';
                        s1[i+1] = '0'; 
                    }  
                   
                    else if(i + 1 < n && s1[i+1] == '0'){
                        ans += 2;
                        s1[i] = '0';
                        s1[i+1] = '0';
                    }
                    else if(i - 1 >= 0 && s1[i-1] == '1'){
                        ans += 2;
                        s1[i] = '0';
                    }
                    else if(i-1 >= 0 && s1[i-1] == '0'){
                        ans += 2;
                        s1[i] = '0';
                    }
                    else return -1;
                }
            }
        }
        return ans;
    }
};