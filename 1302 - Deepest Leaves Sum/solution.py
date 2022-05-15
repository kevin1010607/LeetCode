# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        res, level = 0, [root]
        while level:
            res = sum(n.val for n in level)
            level = [i for n in level for i in (n.left, n.right) if i]
        return res;