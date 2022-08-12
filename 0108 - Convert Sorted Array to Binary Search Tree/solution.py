# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, A: List[int]) -> Optional[TreeNode]:
        def solve(l, r):
            if l > r:
                return None
            mid = l+(r-l)//2
            return TreeNode(A[mid], solve(l, mid-1), solve(mid+1, r))
        return solve(0, len(A)-1)