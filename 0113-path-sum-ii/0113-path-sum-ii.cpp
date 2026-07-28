/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>ans;
    void fun(TreeNode* root,int sum,int tar,vector<int>temp){
        if(!root) return;
        if(root -> left == NULL && root -> right == NULL && sum + root -> val == tar){
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        int k = root -> val + sum;
        temp.push_back(root->val);
        fun(root->left,k,tar,temp);
        fun(root->right,k,tar,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<int>temp;
       fun(root,0,tar,temp);
       return ans;
    }
};