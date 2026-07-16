class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int i = 0;
        int j = 0;
        int n = str1.size();
        int m = str2.size();
        while(i < n && j < m){
            if(str1[i] == str2[j]){
                ans += str1[i];
            }
            else break;
            i++;
            j++;
        }
        while(ans.size() > 0){
          int a = 0;
          int b = 0;
          int c = 0;
          int d = ans.size();
          bool flag = true;
          for(int k=0;k<n;k++){
              if(str1[k] != ans[c]){
                  flag = false;
                  break;
              }
              c++;
              if(c == d) c = 0;
          }
            if(c != 0) flag =false;
             for(int k=0;k<m;k++){
              if(str2[k] != ans[c]){
                  flag = false;
                  break;
              }
              c++;
              if(c == d) c = 0;
          }
            if(c != 0) flag =false;
            if(flag) return ans;
            ans.pop_back();
        } 
        return "";
    }
};