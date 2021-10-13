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
    TreeNode* createBst(vector<int>& v, int l, int r){
        if(l >= r) return nullptr;
        TreeNode* root = new TreeNode(v[l]);
        int idx = l+1;
        while(idx<r && v[idx]<root->val) idx++;
        root->left = createBst(v, l+1, idx);
        root->right = createBst(v, idx, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createBst(preorder, 0, preorder.size());
    }
};