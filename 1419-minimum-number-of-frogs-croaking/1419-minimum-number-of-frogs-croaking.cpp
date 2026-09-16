class Solution {
public:
    int minNumberOfFrogs(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(auto it : s)mp[it]++;
        if(mp.size() == 5 && mp['c'] == mp['r'] && mp['r'] == mp['o'] && mp['o'] == mp['a'] && mp['a'] == mp['k'] && mp['c'] >0){
            int cnt = 0;
            int ans = 0;
            unordered_map<int,int>idx;
            for(int i=0;i<n;i++){
                if(s[i] == 'c'){
                    cnt++;
                    idx[0]++;
                }
                else if(s[i] == 'r'){
                    if(idx[0] >= 1){
                        idx[0]--;
                        idx[1]++;
                    }
                    else return -1;
                }
                else if(s[i] == 'o'){
                    if(idx[1] >= 1 ){
                        idx[1]--;
                        idx[2]++;
                    }
                    else return -1;
                }
                else if(s[i] == 'a'){
                    if(idx[2] >= 1){
                        idx[2]--;
                        idx[3]++;
                    }
                    else return -1;
                }
                else if(s[i] == 'k'){
                    if(idx[3] >= 1){
                        idx[3]--;
                        cnt--;
                    }
                    else return -1;
                }
                ans = max(ans,cnt);
            }
            return ans;
        }
        return -1;
    
    }
};