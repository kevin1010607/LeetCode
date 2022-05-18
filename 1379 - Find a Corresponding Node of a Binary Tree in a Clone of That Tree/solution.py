# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, A: TreeNode, B: TreeNode, t: TreeNode) -> TreeNode:
        return B if not A or A == t else self.getTargetCopy(A.left, B.left, t) or self.getTargetCopy(A.right, B.right, t);