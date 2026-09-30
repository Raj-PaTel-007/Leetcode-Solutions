
class Solution {
public:

    int dist(vector<int>& a, vector<int>& b){
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx*dx + dy*dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2,
                     vector<int>& p3, vector<int>& p4) {

        vector<vector<int>> p = {p1, p2, p3, p4};
        map<int,int> mp;

        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                mp[dist(p[i], p[j])]++;
            }
        }

        int f4 = 0, f2 = 0;

        for(auto &x : mp){
            if(x.first == 0) return false;
            if(x.second == 4) f4++;
            if(x.second == 2) f2++;
        }

        return (f4 == 1 && f2 == 1);
    }
};