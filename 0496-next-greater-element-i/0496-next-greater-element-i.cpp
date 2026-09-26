class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        stack<int>s;
        unordered_map<int,int>ans;
        int n=arr.size();
        ans[arr[n-1]]= -1;
        s.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
                int k=arr[i];
                while(!s.empty()&& k>s.top()){
                    s.pop();
                }
            if(s.empty()) ans[arr[i]]=-1;
            else ans[arr[i]]=s.top();
                s.push(arr[i]);
            
        }
        int m=nums1.size();
        vector<int>v(m);
        for(int i=0;i<m;i++){
            v[i]=ans[nums1[i]];
        }
        return v;
    }
};