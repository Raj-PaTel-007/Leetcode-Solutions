class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dis(n,vector<int>(m,1e6));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0],0,0});


        dis[0][0] = 0;

        while(!pq.empty()){

            vector<int>temp = pq.top();
            pq.pop();

            int w = temp[0];
            int x = temp[1];
            int y = temp[2];

            if(x == n-1 && y == m-1) return true;

            int dx[4] = {-1,0,0,1};
            int dy[4] = {0,-1,1,0};


            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(dis[nx][ny] > w + grid[nx][ny]){
                        dis[nx][ny] = w + grid[nx][ny];
                        if(dis[nx][ny] < health) pq.push({dis[nx][ny] , nx , ny});
                    }
                }
            }
        }
        return false;
    }
};