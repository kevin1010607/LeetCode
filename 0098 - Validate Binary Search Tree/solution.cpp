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
    bool isValidBST(TreeNode* root) {
        int *pre = nullptr;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            if(pre && root->val<=*pre) 
                return false;
            pre = &(root->val), root = root->right;
        }
        return true;
    }
};