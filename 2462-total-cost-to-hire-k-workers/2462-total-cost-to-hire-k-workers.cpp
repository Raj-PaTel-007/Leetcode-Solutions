#define ll long long int

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<ll, vector<ll>, greater<ll>> pq1, pq2;

        int n = costs.size();
        int i = 0;
        int j = n - 1;

        int cnt = 0;

        while (cnt < candidates && i <= j) {
            pq1.push(costs[i]);
            i++;
            cnt++;
        }

        cnt = 0;

        while (cnt < candidates && i <= j) {
            pq2.push(costs[j]);
            j--;
            cnt++;
        }

        ll ans = 0;
        cnt = 0;

        while (cnt < k) {
            ll el1 = pq1.empty() ? 1e18 : pq1.top();
            ll el2 = pq2.empty() ? 1e18 : pq2.top();

            if (el1 <= el2) {
                ans += el1;
                pq1.pop();

                if (i <= j) {
                    pq1.push(costs[i]);
                    i++;
                }
            }
            else {
                ans += el2;
                pq2.pop();

                if (i <= j) {
                    pq2.push(costs[j]);
                    j--;
                }
            }

            cnt++;
        }

        return ans;
    }
};