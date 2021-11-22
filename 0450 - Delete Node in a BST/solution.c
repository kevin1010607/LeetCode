/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(!root) return root;
    if(key < root->val) root->left = deleteNode(root->left, key);
    else if(key > root->val) root->right = deleteNode(root->right, key);
    else{
        if(root->left && root->right){
            struct TreeNode *tmp = root->left;
            while(tmp->right) tmp = tmp->right;
            root->val = tmp->val;
            root->left = deleteNode(root->left, tmp->val);
        }
        else{
            struct TreeNode *tmp = root;
            root = root->left?root->left:root->right;
            free(tmp);
        }
    }
    return root;
}