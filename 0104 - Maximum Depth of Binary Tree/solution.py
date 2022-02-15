# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        res, q = 0, [root] if root else None
        while q:
            q = [p for node in q for p in (node.left, node.right) if(p)]
            res += 1
        return res
        