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
    void fun(TreeNode* root,int mx){
        if(!root) return;
        if(root -> val >= mx) ans++;
        int p = max(mx,root->val);
        fun(root->left,p);
        fun(root->right,p);
    }

    int goodNodes(TreeNode* root) {
        fun(root,INT_MIN);
        return ans;
    }
};