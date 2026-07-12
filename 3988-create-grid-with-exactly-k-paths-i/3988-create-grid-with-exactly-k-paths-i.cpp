class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        vector<string>grid(n,string(m,'#'));
        grid[n-1][m-1] = '.';
        if(k == 1){
            for(int i=0;i<m;i++) grid[0][i] = '.';
            for(int i=0;i<n;i++) grid[i][m-1] = '.';
        }
        else if(k == 2){
            if(n == 1 || m == 1) return {};
            for(int i=0;i<m;i++) grid[0][i] = '.';
            for(int i=0;i<n;i++) grid[i][m-1] = '.';
            grid[1][m-2] = '.';
        }
        else if(k == 3){
             if(n == 1 || m == 1) return {};
            if(m == 2 && n == 2) return {};
            if(m == 2 || n == 2){
                if(n == 2){
                        for(int i=0;i<m;i++) grid[0][i] = '.';
                        for(int i=0;i<n;i++) grid[i][m-1] = '.';
                        grid[1][m-2] = '.';
                        grid[1][m-3] = '.';
                }
                else{
                    for(int i=0;i<m;i++) grid[0][i] = '.';
                        for(int i=0;i<n;i++) grid[i][m-1] = '.';
                        grid[1][0] = '.';
                        grid[2][0] = '.';
                }
            }
            else{
                for(int i=0;i<m;i++) grid[0][i] = '.';
             for(int i=0;i<n;i++) grid[i][m-1] = '.';
                        grid[1][m-2] = '.';
                        grid[1][m-3] = '.';
            }
        }
        else{
            if(n == 1 || m==1) return {};
            if(n <= 3 && m < 3 || (m <= 3 && n < 3)) return {};
            if(n == 2 || m == 2){
                if(n == 2){
                    for(int i=0;i<m;i++) grid[0][i] = '.';
                    grid[1][m-2] = '.';
                    grid[1][m-3] = '.';
                    grid[1][m-4] = '.';
                    return grid;
                }
                else{
                    for(int i=0;i<n;i++) grid[i][0] = '.';
                    grid[n-2][1] = '.';
                    grid[n-3][1] = '.';
                    grid[n-4][1] = '.';
                    return grid;
                }
            }
            if(n == 3 && m == 3){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid[i][j] = '.';
                    }
                }
                grid[0][m-1] = '#';
                grid[n-1][0] = '#';
                return grid;
            }
              for(int i=0;i<m;i++) grid[0][i] = '.';
             for(int i=0;i<n;i++) grid[i][m-1] = '.';
              if(n == 3){
                  grid[1][m-2] = '.';
                    grid[1][m-3] = '.';
                    grid[1][m-4] = '.';
                  return grid;
              }
            else if(m==3){
                grid[1][1] = '.';
                    grid[2][1] = '.';
                    grid[3][1] = '.';
                return grid;
            }
            else{
                 grid[1][m-2] = '.';
                    grid[1][m-3] = '.';
                    grid[1][m-4] = '.';
                  return grid;
            }
            
        }
        grid[n-1][m-1] = '.';
        return grid;
    }
};