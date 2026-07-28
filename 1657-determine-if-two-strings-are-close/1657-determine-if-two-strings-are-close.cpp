class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n != m) return false;
        unordered_map<char,int>mp1;
        for(auto it : word1)mp1[it]++;
        unordered_map<char,int>mp2;
        for(auto it : word2)mp2[it]++;
        if(mp1.size() != mp2.size()) return false;
        vector<pair<char,int>>vp1;
        vector<pair<char,int>>vp2;
        for(auto it1 : mp1){
            vp1.push_back(it1);
        }
        for(auto it2 : mp2){
            vp2.push_back(it2);
        }
        sort(vp1.begin(),vp1.end(),[&](pair<int,int>A,pair<int,int>B){
            return A.second > B.second;
        });
         sort(vp2.begin(),vp2.end(),[&](pair<int,int>A,pair<int,int>B){
            return A.second > B.second;
        });
        int sz = vp1.size();
        for(int i=0;i<sz;i++){
            char ch1 = vp1[i].first;
            char ch2 = vp2[i].first;
            if(mp1.find(ch2) == mp1.end() || mp2.find(ch1) == mp2.end() || vp1[i].second != vp2[i].second) return false;
        }
        return true;
    }
};