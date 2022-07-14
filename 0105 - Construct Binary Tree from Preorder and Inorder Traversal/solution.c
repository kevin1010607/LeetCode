/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* newNode(int val, struct TreeNode *left, struct TreeNode *right){
    struct TreeNode *res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    res->val = val, res->left = left, res->right = right;
    return res;
}
struct TreeNode* build(int *preorder, int *inorder, int l, int r){
    if(l > r) return NULL;
    int mid = l;
    while(inorder[mid] != *preorder) mid++;
    struct TreeNode *left = build(preorder+1, inorder, l, mid-1);
    struct TreeNode *right = build(preorder+(mid-l+1), inorder, mid+1, r);
    return newNode(*preorder, left, right);
}
struct TreeNode* buildTree(int* preorder, int preorderSz, int* inorder, int inorderSz){
    return build(preorder, inorder, 0, inorderSz-1);
}