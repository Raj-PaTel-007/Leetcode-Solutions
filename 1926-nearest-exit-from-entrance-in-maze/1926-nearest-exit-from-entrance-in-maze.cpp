class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<vector<int>>q;
        q.push(entrance);
        int x = entrance[0];
        int y = entrance[1];
        int cnt = 0;
        maze[x][y] = '+';
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<int>temp = q.front();
                q.pop();
                int r = temp[0];
                int c = temp[1];
                if(r == 0 || r == n-1 || c == 0 || c == m-1){
                    if(r == x && c == y){}
                    else return cnt;
                }
                int dr[4] = {-1,0,0,1};
                int dc[4] = {0,-1,1,0};
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '.'){
                        maze[nr][nc] = '+';
                        q.push({nr,nc});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};