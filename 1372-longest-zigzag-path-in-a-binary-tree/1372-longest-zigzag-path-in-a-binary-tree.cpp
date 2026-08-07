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
    pair<int,int> fun(TreeNode* root){
         if(!root) return {-1,-1};
         pair<int,int>p1 = fun(root -> left);
         pair<int,int>p2 = fun(root -> right);
         int a = p1.first + 1;
         int b = p2.second + 1;
         int mx = max(a,b);
         ans = max(mx,ans);
         return {b,a};
    }

    int longestZigZag(TreeNode* root) {
        fun(root);
        return ans;
    }
};