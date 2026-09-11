class Solution {
public:
    int totalNumbers(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_set<int> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == i) continue;

                for(int k=0;k<n;k++){
                    if(k == i || k == j) continue;

                    if(arr[i] != 0 && arr[k] % 2 == 0){
                        int num = arr[i]*100 + arr[j]*10 + arr[k];

                        if(st.find(num) == st.end()){
                            ans++;
                            st.insert(num);
                        }
                    }
                }
            }
        }

        return ans;
    }
};