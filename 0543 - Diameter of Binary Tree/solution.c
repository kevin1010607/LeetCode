/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) a>b?a:b
int dfs(struct TreeNode* root, int *ret){
    if(!root) return -1;
    int l = dfs(root->left, ret)+1, r = dfs(root->right, ret)+1;
    *ret = max(*ret, l+r);
    return max(l, r);
}
int diameterOfBinaryTree(struct TreeNode* root){
    int ret = 0;
    dfs(root, &ret);
    return ret;
}