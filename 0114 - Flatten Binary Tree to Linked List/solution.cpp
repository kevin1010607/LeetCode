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
private:
    TreeNode* dfs(TreeNode *root){
        if(!root) return nullptr;
        TreeNode *l = dfs(root->left), *r = dfs(root->right);
        if(!l) return r?:root;
        l->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return r?:l;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
};