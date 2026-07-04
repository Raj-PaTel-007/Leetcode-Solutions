class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>v;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(i==n){
            while(j<m){
                v.push_back(nums2[j]);
                j++;
            }
        }

            if(j==m){
            while(i<n){
                v.push_back(nums1[i]);
                i++;
            }
        }
        int p=v.size();
      
        double av;
        if(p%2!=0){
            int idx=(p)/2;
            av=v[idx];
        
        }
        else{
            int idx1=(p/2)-1;
            int idx2=idx1+1;
            double sum=v[idx1]+v[idx2];
            av=sum/2;
        }
        return av;
    }
};