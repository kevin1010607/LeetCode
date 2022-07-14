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
private:
    TreeNode* build(vector<int>& preorder, int& idx, vector<int>& inorder, int l, int r, unordered_map<int, int>& m){
        if(l > r) return nullptr;
        int mid = m[preorder[idx]];
        TreeNode *res = new TreeNode(preorder[idx++]);
        res->left = build(preorder, idx, inorder, l, mid-1, m);
        res->right = build(preorder, idx, inorder, mid+1, r, m);
        return res;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), idx = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) m[inorder[i]] = i;
        return build(preorder, idx, inorder, 0, n-1, m);
    }
};