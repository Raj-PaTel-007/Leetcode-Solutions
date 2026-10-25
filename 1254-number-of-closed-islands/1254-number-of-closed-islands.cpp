class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, bool &flag) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        if(i == 0 || j == 0 || i == n-1 || j == m-1) {
            flag = false;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && x < n && y >= 0 && y < m &&
               grid[x][y] == 0 && !vis[x][y]) {
                dfs(x, y, grid, vis, flag);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 && !vis[i][j]) {
                    bool flag = true;
                    dfs(i, j, grid, vis, flag);

                    if(flag) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};