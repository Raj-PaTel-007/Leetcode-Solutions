class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(ans<m[nums[i]]){
                ans=m[nums[i]];
            }

        }
        int a=0;
        for(int i=0;i<=100;i++){
            if(m[i]==ans){
                a+=ans;
            }
        }
     return a;
        
    }
};