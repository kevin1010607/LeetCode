/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int*)malloc(100*sizeof(int)), idx = 0;
    struct TreeNode *now = root;
    while(now){
        if(!now->left){
            res[idx++] = now->val;
            now = now->right;
        }
        else{
            struct TreeNode *tmp = now->left;
            while(tmp->right && tmp->right!=now) tmp = tmp->right;
            if(tmp->right){
                res[idx++] = now->val;
                tmp->right = NULL;
                now = now->right;
            }
            else{
                tmp->right = now;
                now = now->left;
            }
        }
    }
    *returnSize = idx;
    return res;
}