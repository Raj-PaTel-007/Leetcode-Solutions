class Solution {
public:

    void fun(int idx,string s, string digits , vector<string>&nums , vector<string>&ans){
        if(idx == digits.size()) {
            ans.push_back(s);
            return;
        }
        string temp = nums[digits[idx] - '0'];
        int n = temp.size();
        for(int i=0;i<n;i++){
            s += temp[i];
            fun(idx+1,s,digits,nums,ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>nums = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s = "";
        vector<string>ans;
        fun(0,s,digits,nums,ans);
        return ans;
    }
};