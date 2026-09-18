class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        map<char,int> mp;
        vector<int> first(26,-1), last(26,-1);
        vector<vector<int>> freq(n,vector<int>(26));

        for(int i=0;i<n;i++) {
            mp[s[i]]++;

            if(i) freq[i] = freq[i-1];
            freq[i][s[i]-'a']++;

            int c = s[i]-'a';

            if(first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        vector<pair<int,int>> v;

        for(int c=0;c<26;c++) {
            if(first[c] == -1) continue;

            int l = first[c], r = last[c];

            for(int x=0;x<26;x++) {
                int cnt = freq[r][x] -
                          (l ? freq[l-1][x] : 0);

                if(cnt)
                    r = max(r,last[x]);
            }

            bool ok = true;

            for(int x=0;x<26;x++) {
                int cnt = freq[r][x] -
                          (l ? freq[l-1][x] : 0);

                if(cnt && cnt != mp['a'+x]) {
                    ok = false;
                    break;
                }
            }

            if(ok)
                v.push_back({l,r});
        }
        if(v.size() == 0) v.push_back({0,n-1});
        sort(v.begin(),v.end(),[](auto &a,auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int lastEnd = -1;

        for(auto [l,r] : v) {
            if(l > lastEnd) {
                ans.push_back(s.substr(l,r-l+1));
                lastEnd = r;
            }
        }

        return ans;
    }
};