/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *newNode(int val){
    struct TreeNode *res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    res->val = val, res->left = res->right = NULL;
    return res;
}
struct TreeNode* buildTree(int* in, int inSize, int* post, int postSize){
    if(inSize <= 0) return NULL;
    int idx = 0;
    while(in[idx] != post[postSize-1]) idx++;
    struct TreeNode *root = newNode(post[postSize-1]);
    root->left = buildTree(in, idx, post, idx);
    root->right = buildTree(in+idx+1, inSize-idx-1, post+idx, postSize-idx-1);
    return root;
}