class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<unordered_set<int>>> vp(n, vector<unordered_set<int>>(m));
        if(grid[0][0] == '('){
            vp[0][0].insert(1);
        }
        else return false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0)continue;
                if(i > 0){
                    int val;
                    if(grid[i][j] == '(') val = 1;
                    else val = -1;
                    for(auto it : vp[i-1][j]){
                        int a = it;
                        if(a + val >= 0) vp[i][j].insert(a + val);
                    }
                }
                if(j > 0){
                    int val;
                    if(grid[i][j] == '(') val = 1;
                    else val = -1;
                    for(auto it : vp[i][j-1]){
                        int a = it;
                        if(a + val >= 0) vp[i][j].insert(a + val);
                    }
                }

            }
        }
        bool ans = false;
        for(auto it : vp[n-1][m-1]){
            if(it == 0) ans = true;
        }
        return ans;
    }
};