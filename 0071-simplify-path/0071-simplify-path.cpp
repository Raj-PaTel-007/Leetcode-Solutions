class Solution {
public:
    string simplifyPath(string s) {
        stack<string>st;
        int n = s.size();
        int i = 0;
        while(i < n){
            while(i < n && s[i] == '/')i++;
            if(i == n) break;

            if(s[i] != '/'){
                int cnt = 0;
                string temp = "";
                int mx = 0;
                while(i < n && s[i] != '/'){
                    temp += s[i];
                    if(s[i] == '.'){
                        cnt++;
                        mx = max(mx,cnt);
                    }
                    else cnt =0;
                    i++;
            
                }
                if(cnt == 2 && temp.size() == 2){
                    if(!st.empty()){
                        cout << st.top();
                        st.pop();
                    }
                }
                else if(!(temp.size() == 1 && s[i-1] == '.')) st.push(temp);
            }
            
        }
        stack<string>st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        string ans = "";
        ans += "/";
        while(!st1.empty()){
            ans += st1.top();
            st1.pop();
            if(!st1.empty()) ans += '/';
        }
        return ans;
    }
};