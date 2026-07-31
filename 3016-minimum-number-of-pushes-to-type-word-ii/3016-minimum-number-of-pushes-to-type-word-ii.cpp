class Solution {
public:

    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second > b.second;
    }

    int minimumPushes(string word) {
        unordered_map<int,int>mp;
        int n = word.size();
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }
       
        vector<pair<int,int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);
        int ans = 0;
        int cnt = 0;
         
        for(auto it:vec){
            cnt++;
            if(cnt<=8){
                
                ans+=it.second;
            }
            else if(cnt>8 && cnt<=16){
                
                ans+=(it.second*2);
            }
            else if(cnt>16 && cnt<=24){
              
                ans+=(it.second*3);
            }
            else{
               
                ans+=(it.second*4);
            }
        }
        return ans;
    }
};