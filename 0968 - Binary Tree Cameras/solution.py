# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        def solve(node):
            if not node.left and not node.right:
                return (1, inf, 0)
            if not node.left or not node.right:
                p1, p2, p3 = 1, inf, 0
                q1, q2, q3 = solve(node.left if node.left else node.right)
                return (min(p1+q1, p1+q2, p1+q3), min(p2+q1, p2+q2, p3+q1), p3+q2)
            tmp = node.right
            node.right = None
            p1, p2, p3 = solve(node)
            q1, q2, q3 = solve(tmp)
            node.right = tmp
            return (min(p1+q1, p1+q2, p1+q3), min(p2+q1, p2+q2, p3+q1), p3+q2)
        return min(solve(root)[0:2])