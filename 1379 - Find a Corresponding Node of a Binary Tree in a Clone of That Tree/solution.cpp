/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* A, TreeNode* B, TreeNode* t) {
        if(!A || A==t) return B;
        return getTargetCopy(A->left, B->left, t)?:getTargetCopy(A->right, B->right, t);
    }
};