# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        now, now.next, n = self, head, 0
        while now.next:
            now = now.next
            n += 1
        now = self
        for i in range(n//k):
            head, tail, now = now, now.next, now.next.next
            for j in range(k-1):
                tail.next = now.next
                now.next = head.next
                head.next = now
                now = tail.next
            now = tail
        return self.next