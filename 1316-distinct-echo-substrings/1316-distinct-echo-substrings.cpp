class Solution {
public:
    int distinctEchoSubstrings(string nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j - i + 1;
                if(i - len >= 0){
                    string str1 = nums.substr(i,len);
                    string str2 = nums.substr(i-len,len);
                    if(str1 == str2 && st.find(str1) == st.end()){
                        cout << str1 << endl;
                        ans++;
                        st.insert(str1);
                    }
                }
            }
        }
        return ans;
    }
};