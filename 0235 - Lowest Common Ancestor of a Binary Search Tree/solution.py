# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        p, q = sorted([p.val, q.val])
        while not p <= root.val <= q:
            root = (root.left, root.right)[p > root.val]
        return root