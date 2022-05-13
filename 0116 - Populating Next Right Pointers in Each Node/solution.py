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
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        head = root
        while head and head.left:
            p = head.left
            while head:
                head.left.next = head.right
                head.right.next = head.next and head.next.left
                head = head.next
            head = p
        return root
        