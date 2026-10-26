class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& grid,
                  vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;
        long long sum = grid[i][j];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if(x >= 0 && x < m && y >= 0 && y < n &&
               grid[x][y] > 0 && !vis[x][y]) {
                sum += dfs(x, y, grid, vis);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = dfs(i, j, grid, vis);

                    if(sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};