# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p, p.next = self, head;
        while p.next and p.next.next:
            a = p.next
            b = a.next
            a.next, b.next, p.next = b.next, a, b
            p = a
        return self.next