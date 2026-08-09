class Solution {
public:
    double minPrice(vector<int>& P, vector<int>& D) {
        sort(P.begin(),P.end());
        sort(D.begin(),D.end());
        double ans = 0;
        int i = P.size() - 1;
        int j = D.size() - 1;
        while(j >= 0 && i >= 0){
            ans += (P[i]*(100.00 - D[j]))/100.00;
            i--;
            j--;
        }
        while(i >= 0){
            ans += P[i];
            i--;
        }
        return ans;
    }
};