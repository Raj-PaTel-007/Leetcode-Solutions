class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int>temp = colors;
        for(int i=0;i<k-1;i++){
           temp.push_back(colors[i]);
        }
        int i = -1;
        int j = -1;
        n = temp.size();
        for(int a=1;a<n;a++){
            if(temp[a] != temp[a-1]){
                i = a - 1;
                j = a ;
                break;
            }
        }
        if(i == -1) return 0;
        int ans = 0;
        while(j - i + 1 < k  && j < n){
            if(temp[j]^temp[j-1]){
                j++;
            }
            else{
                i = j;
                j++;
            }
        }
        if(j - i +1 <k) return 0;
        cout << n << endl;
        while(j < n){
            if(temp[j] ^ temp[j-1]){
                if(j - i + 1 >= k) ans++;
            }
            else{
                i = j;
            }
            j++;
        }
        return ans;
    }
};