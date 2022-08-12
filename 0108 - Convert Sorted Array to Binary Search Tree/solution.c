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
struct TreeNode* solve(int *A, int l, int r){
    if(l > r) return NULL;
    int mid = l+(r-l)/2;
    return newNode(A[mid], solve(A, l, mid-1), solve(A, mid+1, r));
}
struct TreeNode* sortedArrayToBST(int* A, int ASz){
    return solve(A, 0, ASz-1);
}