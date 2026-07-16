class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it : queries){
            int a = it[0];
            int b=it[1];
            int cnt = 0;
            while(a != b){
                if(a > b){
                    a = a/2;
                    cnt++;
                }
                else{
                    b = b/2;
                    cnt++;
                }
            }
            ans.push_back(cnt+1);
        }
        return ans;
    }
};