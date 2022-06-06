/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *A, struct ListNode *B) {
    struct ListNode *nowA = A, *nowB = B;
    while(nowA != nowB){
        nowA = nowA?nowA->next:B;
        nowB = nowB?nowB->next:A;
    }
    return nowA;
}