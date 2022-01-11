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
    void dfs(TreeNode *root, int &res, int now){
        now = (now<<1)|root->val;
        if(!root->left && !root->right) res += now;
        if(root->left) dfs(root->left, res, now);
        if(root->right) dfs(root->right, res, now);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
};