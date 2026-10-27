class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string>ans(n);
        
        for(int i=0;i<n;i++){
             string str = "";
            if(i == 0){
        for(int i=0;i<m;i++){
            str += ".";
        }
            }
            else{
                for(int i=0;i<m-1;i++){
                    str += "#";
                    
                }
                str += ".";
            }
            ans[i] = str;
        }
        return ans;
    }
};