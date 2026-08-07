class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if(arr.size() == 1){
            if(arr[0] == 0 && n <= 1 || (arr[0] == 1 && n == 0)) return true;
            return false;
        }
        for(int i=0;i<arr.size();i++){
            if(i+1 < arr.size() && i == 0 && arr[i] == 0 && arr[i+1] == 0){
                arr[i] = 1;
                n--;
            }
            else if(i == arr.size()-1 && arr[i] == 0 && arr[i-1] == 0){
                arr[i] = 1;
                n--;
            }
            else if(i > 0 && i + 1< arr.size() && arr[i] == 0 && arr[i-1] == 0 && arr[i+1] == 0){
                arr[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};