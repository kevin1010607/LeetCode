# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def lt(self, other):
    return self.val <= other.val
ListNode.__lt__ = lt

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        import heapq
        head = now = ListNode()
        h = [i for i in lists if i]
        heapq.heapify(h)
        while h:
            now.next = heapq.heappop(h)
            now = now.next
            if now.next:
                heapq.heappush(h, now.next)
        return head.next