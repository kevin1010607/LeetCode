/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* newNode(int val){
    struct TreeNode *ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val = val, ret->left = ret->right = NULL;
    return ret;
}
struct TreeNode* bstFromPreorder(int *preorder, int preorderSize){
    if(preorderSize <= 0) return NULL;
    struct TreeNode *root = newNode(preorder[0]);
    int idx = 1;
    while(idx<preorderSize && preorder[idx]<root->val) idx++;
    root->left = bstFromPreorder(preorder+1, idx-1);
    root->right = bstFromPreorder(preorder+idx, preorderSize-idx);
    return root;
}