/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum(struct TreeNode* root, int *res){
    if(!root) return 0;
    int l = sum(root->left, res), r = sum(root->right, res);
    (*res) += abs(l-r);
    return l+r+root->val;
}
int findTilt(struct TreeNode* root){
    int res = 0;
    sum(root, &res);
    return res;
}