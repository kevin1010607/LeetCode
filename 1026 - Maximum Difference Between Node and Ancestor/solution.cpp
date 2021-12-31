/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int ma=INT_MIN, int mi=INT_MAX) {
        if(!root) return ma-mi;
        return max(maxAncestorDiff(root->left, max(ma, root->val), min(mi, root->val)),
                   maxAncestorDiff(root->right, max(ma, root->val), min(mi, root->val)));
    }
};