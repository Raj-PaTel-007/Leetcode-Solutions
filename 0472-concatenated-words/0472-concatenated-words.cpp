class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& arr) {
        unordered_set<string>st;
        for(auto it : arr) st.insert(it);
        int n = arr.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            string str = arr[i];
            int sz = str.size();
            vector<int>dp(sz + 1,INT_MIN);
            dp[0] = 0;
            for(int i=1;i<=sz;i++){
                for(int j=i;j<=sz;j++){
                    int a = i-1;
                    int b = j-1;
                    string temp = str.substr(a,b-a+1);
                    if(st.count(temp)) dp[j] = max(dp[j],dp[i-1] + 1);
                }
            }
            if(dp[sz] > 1) ans.push_back(str);
        }
        return ans;
    }
};