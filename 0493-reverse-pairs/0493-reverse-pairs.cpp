class Solution {
public:
    int ans = 0;
    void merge(int left,int mid,int right,vector<int>&nums){
      int i = left;
      int j = mid+1;
      while(j <= right){
          while(i <= mid && nums[i] <= 2LL*nums[j]) i++;
         if(i <= mid) ans += mid - i + 1;
         j++;
      }
      i = left;
      j = mid + 1;
      vector<int>temp;
      while(i <= mid && j <= right){
          if(nums[i] < nums[j]){
            temp.push_back(nums[i]);
            i++;
          }
          else{
            temp.push_back(nums[j]);
            j++;
          }
      }
      while(i <= mid){
        temp.push_back(nums[i]);
        i++;
      }
      while(j <= right){
        temp.push_back(nums[j]);
        j++;
      }
     for(int i = left;i<=right;i++){
        nums[i] = temp[i-left];
     }
   }

  void fun(int left , int right , vector<int>&nums){
      if(left >= right) return;
      int mid = (left + right)/2;
      fun(left,mid,nums);
      fun(mid+1,right,nums);
      merge(left,mid,right,nums);
  }
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        fun(0,n-1,arr);
        return ans;
    }
};