class Solution{
    public:
    vector<int>twoSum(vector<int>& nums,int target){
        vector<int>v;
        unordered_map<int,int>k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int m=nums[i];
            int s=target-m;
            if(k.find(s)!=k.end()){
                v.push_back(k[s]);
                v.push_back(i);
            }
            else{
                k.insert({m,i});
            }
        }
        return v;
    }
};