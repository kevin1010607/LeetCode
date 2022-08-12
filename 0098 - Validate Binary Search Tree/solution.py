# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode], mi=-inf, ma=inf) -> bool:
        if not root:
            return True
        if not (mi < root.val < ma):
            return False
        return self.isValidBST(root.left, mi, root.val) and self.isValidBST(root.right, root.val, ma)