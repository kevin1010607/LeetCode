/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int *res, int now){
    now = (now<<1)|root->val;
    if(!root->left && !root->right) *res += now;
    if(root->left) dfs(root->left, res, now);
    if(root->right) dfs(root->right, res, now);
}
int sumRootToLeaf(struct TreeNode* root){
    int res = 0;
    dfs(root, &res, 0);
    return res;
}