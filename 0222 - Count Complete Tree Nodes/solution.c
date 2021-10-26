/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root){
    if(!root) return 0;
    int l = 0, r = 0;
    struct TreeNode *tl = root, *tr = root;
    while(tl = tl->left) l++;
    while(tr = tr->right) r++;
    return (l==r)?((1<<l+1)-1):(1+countNodes(root->left)+countNodes(root->right));
}