#define ll long long int

class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& pen) {

        vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(m, vector<ll>(2, 1e18)));
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>pq;

        pq.push({1, 1, 0, 0});
        dist[0][0][1] = 1;

        while (!pq.empty()) {
            vector<ll> temp = pq.top();
            pq.pop();
            ll val = temp[0];
            ll rem = temp[1];
            ll i = temp[2];
            ll j = temp[3];
            if (val > dist[i][j][rem & 1]) continue;

            if (i == n - 1 && j == m - 1) {
                return val;
            }

            ll np = (rem + 1) & 1;

            if (rem & 1) {
                ll nx = i + 1;
                ll ny = j + 1;

                if (nx < n) {
                    ll k = (nx + 1) * (j + 1);
                    k += val;

                    if (k < dist[nx][j][np]) {
                        dist[nx][j][np] = k;
                        pq.push({k, rem + 1, nx, j});
                    }
                }

                if (ny < m) {
                    ll k = (i + 1) * (ny + 1);
                    k += val;

                    if (k < dist[i][ny][np]) {
                        dist[i][ny][np] = k;
                        pq.push({k, rem + 1, i, ny});
                    }
                }

                nx = i - 1;
                ny = j - 1;

                if (nx >= 0) {
                    ll k = (nx + 1) * (j + 1);
                    k += val;
                    k += pen[i][j];

                    if (k < dist[nx][j][np]) {
                        dist[nx][j][np] = k;
                        pq.push({k, rem + 1, nx, j});
                    }
                }

                if (ny >= 0) {
                    ll k = (i + 1) * (ny + 1);
                    k += val;
                    k += pen[i][j];

                    if (k < dist[i][ny][np]) {
                        dist[i][ny][np] = k;
                        pq.push({k, rem + 1, i, ny});
                    }
                }

                ll a = val + pen[i][j];

                if (a < dist[i][j][np]) {
                    dist[i][j][np] = a;
                    pq.push({a, rem + 1, i, j});
                }
            }
            else {

                ll nx = i - 1;
                ll ny = j - 1;

                if (nx >= 0) {
                    ll k = (nx + 1) * (j + 1);
                    k += val;

                    if (k < dist[nx][j][np]) {
                        dist[nx][j][np] = k;
                        pq.push({k, rem + 1, nx, j});
                    }
                }

                if (ny >= 0) {
                    ll k = (i + 1) * (ny + 1);
                    k += val;

                    if (k < dist[i][ny][np]) {
                        dist[i][ny][np] = k;
                        pq.push({k, rem + 1, i, ny});
                    }
                }

                nx = i + 1;
                ny = j + 1;

                if (nx < n) {
                    ll k = (nx + 1) * (j + 1);
                    k += val;
                    k += pen[i][j];

                    if (k < dist[nx][j][np]) {
                        dist[nx][j][np] = k;
                        pq.push({k, rem + 1, nx, j});
                    }
                }

                if (ny < m) {
                    ll k = (i + 1) * (ny + 1);
                    k += val;
                    k += pen[i][j];

                    if (k < dist[i][ny][np]) {
                        dist[i][ny][np] = k;
                        pq.push({k, rem + 1, i, ny});
                    }
                }

                ll a = val + pen[i][j];

                if (a < dist[i][j][np]) {
                    dist[i][j][np] = a;
                    pq.push({a, rem + 1, i, j});
                }
            }
        }

        return -1;
    }
};