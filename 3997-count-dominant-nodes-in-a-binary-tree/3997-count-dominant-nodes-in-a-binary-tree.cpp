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
#define ll long long int
class Solution {
public:
    int ans = 0;
    ll fun(TreeNode* root){
        if(!root) return INT_MIN;
        ll l = fun(root->left);
        ll r  = fun(root->right);
        ll x = root->val;
        if(x >= l && x >= r){
            ans++;
        }
        return max({l,r,x});
    }
    int countDominantNodes(TreeNode* root) {
        fun(root);
        return ans;
    }
};