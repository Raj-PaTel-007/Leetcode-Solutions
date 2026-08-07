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

    vector<int>v1;
    vector<int>v2;

    void fun1(TreeNode* root){
        if(!root) return;
        fun1(root -> left);
        if(!root -> left && !root -> right){
            v1.push_back(root -> val);
        }
        fun1(root -> right);
    }

    void fun2(TreeNode* root){
        if(!root) return;
        fun2(root -> left);
        if(!root -> left && !root -> right){
            v2.push_back(root -> val);
        }
        fun2(root -> right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        fun1(root1);
        fun2(root2);
        if(v1.size() != v2.size()) return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i] != v2[i])return false;
        }
        return true;
    }
};