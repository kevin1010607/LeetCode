/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root){
    struct TreeNode *now = root;
    while(now){
        if(now->left){
            struct TreeNode *pre = now->left;
            while(pre->right) pre = pre->right;
            pre->right = now->right;
            now->right = now->left;
            now->left = NULL;
        }
        now = now->right;
    }
    return root;
}