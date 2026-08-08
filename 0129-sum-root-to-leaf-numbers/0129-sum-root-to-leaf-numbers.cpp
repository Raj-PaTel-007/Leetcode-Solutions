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

    int ans = 0;

    void fun(TreeNode* root,int val){
        if(!root -> left && !root -> right){
            ans += val;
            return;
        }
        if(root -> left){
            fun(root->left,val*10 + root ->left->val);
        }
        if(root -> right){
            fun(root -> right,val*10 + root->right->val);
        }
    }

    int sumNumbers(TreeNode* root) {
        fun(root,root->val);
        return ans;
    }
};