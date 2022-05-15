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
#define P pair<int, int>
#define F first
#define S second
class Solution {
private:
    P dfs(TreeNode *root){
        if(!root) return {0, 0};
        if(!root->left && !root->right) return {root->val, 1};
        auto [v1, d1] = dfs(root->left);
        auto [v2, d2] = dfs(root->right);
        if(d1 == d2) return {v1+v2, d1+1};
        else if(d1 > d2) return {v1, d1+1};
        else return {v2, d2+1};
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        return dfs(root).F;
    }
};