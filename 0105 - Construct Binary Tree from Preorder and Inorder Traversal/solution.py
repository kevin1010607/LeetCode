# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if inorder:
            idx = inorder.index(preorder.pop(0))
            res = TreeNode(inorder[idx])
            res.left = self.buildTree(preorder, inorder[:idx])
            res.right = self.buildTree(preorder, inorder[idx+1:])
            return res
        return None