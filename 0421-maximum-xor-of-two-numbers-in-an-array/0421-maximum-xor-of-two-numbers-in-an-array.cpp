class TrieNode{
 public:
 vector<TrieNode*>child;
    TrieNode(){
        child.resize(2);
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            TrieNode* curr = root;
            int num = nums[i];
            int cnt = 31;
            for(int j=31;j>=0;j--){
                if(num & (1LL << j)){
                    if(!curr -> child[1]){
                        TrieNode* temp = new TrieNode();
                        curr -> child[1] = temp;
                    }
                    curr = curr -> child[1];
                }
                else{
                    if(!curr -> child[0]){
                        TrieNode* temp = new TrieNode();
                        curr -> child[0] = temp;
                    }
                    curr = curr -> child[0];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            int sum = 0;
            TrieNode* curr = root;
            for(int j=31;j>=0;j--){
                if(num & (1LL << j)){
                    if(curr -> child[0]){
                        sum += 1LL << j;
                        curr = curr -> child[0];
                    }
                    else if(curr->child[1]) curr = curr -> child[1];
                }
                else{
                    if(curr -> child[1]){
                        sum += 1LL << j;
                        curr = curr -> child[1];
                    }
                    else if(curr -> child[0]) curr = curr -> child[0];
                }
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};