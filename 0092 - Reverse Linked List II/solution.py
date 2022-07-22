# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        self.next, pre = head, self
        for _ in range(left-1):
            pre = pre.next
        tail = pre.next
        for _ in range(right-left):
            tmp = pre.next
            pre.next = tail.next
            tail.next = pre.next.next
            pre.next.next = tmp
        return self.next