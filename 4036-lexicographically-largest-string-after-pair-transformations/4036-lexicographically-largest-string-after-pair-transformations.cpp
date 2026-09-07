class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            string temp = "";
            while(num > 0 ){
                int j = 0;
                while(1LL << j <= num && j <= 25) j++;
                j--;
                temp += 'a' + j ;
                num -= 1LL << j;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};