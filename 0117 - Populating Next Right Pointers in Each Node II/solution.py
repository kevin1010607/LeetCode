"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head, p, self.next = root, self, None
        while head:
            if head.left:
                p.next = head.left
                p = p.next
            if head.right:
                p.next = head.right
                p = p.next
            if head.next:
                head = head.next
            else:
                head = self.next
                p, self.next = self, None
        return root