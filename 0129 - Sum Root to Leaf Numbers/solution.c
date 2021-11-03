/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root){
    return dfs(root, 0);
}
int dfs(struct TreeNode* root, int sum){
    if(!root) return 0;
    if(!root->left && !root->right) return 10*sum+root->val;
    return dfs(root->left, 10*sum+root->val)+dfs(root->right, 10*sum+root->val);
}