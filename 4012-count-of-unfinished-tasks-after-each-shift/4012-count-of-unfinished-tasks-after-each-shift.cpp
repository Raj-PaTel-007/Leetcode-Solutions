#define ll long long int
class Solution {
public:
    vector<int> countTasks(vector<int>& ar, vector<int>& shifts) {
        int n = ar.size();
        vector<ll>arr(n,0);
        arr[0] = ar[0];
        for(int i=1;i<n;i++) arr[i] = arr[i-1] + ar[i];
        vector<int>ans;
        ll sum = 0;
        for(auto a : shifts){
            sum += a;
            cout << sum << endl;
            auto it = lower_bound(arr.begin(),arr.end(),sum+1);
            if(it == arr.end()){
                ans.push_back(0);
                sum = 0;
            }
            else{
                int idx = it - arr.begin();
                int diff = n - idx;
                ans.push_back(diff);
            }
        }
        return ans;
    }
};