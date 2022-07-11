# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res, q = [], [root] if root else []
        while q:
            res.append(q[-1].val)
            q = [n for i in q for n in (i.left, i.right) if n]
        return res