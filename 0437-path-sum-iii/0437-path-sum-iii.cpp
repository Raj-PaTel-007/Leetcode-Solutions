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
    
    void fun(TreeNode* root,ll sum ,ll tar,unordered_map<ll,ll>&mp){
        if(!root) return;
        ll s = sum + root->val;
        if(mp[s-tar] > 0)ans += mp[s-tar];
        if(s == tar) ans++;
        mp[s]++;
        fun(root->left,s,tar,mp);
        fun(root->right,s,tar,mp);
        mp[s]--;
    }

    int pathSum(TreeNode* root, int tar) {
        if(!root)return 0;
        unordered_map<ll,ll>mp;
        fun(root,0,tar,mp);
        return ans;
    }
};