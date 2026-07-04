class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0, j = 0;
        int n = s.length();
        int mx = 0;
        
        while (j < n) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                mx = max(mx, j - i + 1);
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        
        return mx;
    }
};