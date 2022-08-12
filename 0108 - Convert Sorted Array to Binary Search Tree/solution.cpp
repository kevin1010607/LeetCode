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
    typedef vector<int>::iterator It;
    TreeNode* solve(It l, It r){
        if(l == r) return nullptr;
        It mid = l+(r-l)/2;
        return new TreeNode(*mid, solve(l, mid), solve(mid+1, r));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& A) {
        return solve(A.begin(), A.end());
    }
};