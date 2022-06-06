/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode *nowA = A, *nowB = B;
        while(nowA != nowB){
            nowA = nowA?nowA->next:B;
            nowB = nowB?nowB->next:A;
        }
        return nowA;
    }
};