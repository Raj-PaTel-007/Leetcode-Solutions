class Solution {
public:
    int countCharacters(vector<string>& vec, string A) {
        sort(A.begin(),A.end());
        int ans = 0;
        for(auto B : vec){
            sort(B.begin(),B.end());
            int i = 0;
            int j = 0;
            int m = B.size();
            int n = A.size();
            while(i < n && j <m){
                if(A[i] == B[j]){
                    i++;
                    j++;
                }
                else i++;
            }
            if(j == m) ans += m; 
        }
        return ans;
    }
};