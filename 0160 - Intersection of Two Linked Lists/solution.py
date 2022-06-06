# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, A: ListNode, B: ListNode) -> Optional[ListNode]:
        nowA, nowB = A, B
        while nowA != nowB:
            nowA = nowA.next if nowA else B
            nowB = nowB.next if nowB else A
        return nowA