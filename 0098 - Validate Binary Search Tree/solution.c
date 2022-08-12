/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool solve(struct TreeNode *root, int **pre){
    if(!root) return true;
    if(!solve(root->left, pre)) return false;
    if(*pre && root->val<=**pre) return false;
    *pre = &(root->val);
    if(!solve(root->right, pre)) return false;
    return true;
}
bool isValidBST(struct TreeNode* root){
    int *pre = NULL;
    return solve(root, &pre);
}