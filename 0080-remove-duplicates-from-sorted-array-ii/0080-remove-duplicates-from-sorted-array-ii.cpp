class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i < n){
            if(i + 1 == n){
                nums[j] = nums[i];
                j++;
                i++;
            }
            else if(nums[i] != nums[i+1]){
                nums[j] = nums[i];
                i++;
                j++;
            }
            else{
                nums[j] = nums[i];
                i++;
                j++;
                nums[j] = nums[i];
                i++;
                j++;
                while(i < n && nums[i] == nums[i-1])i++;
            }
        }
        return j;
    }
};