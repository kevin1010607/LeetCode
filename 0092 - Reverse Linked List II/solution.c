/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode dummy, *pre = &dummy, *tail, *tmp;
    dummy.next = head;
    for(int i = 0; i < left-1; i++) pre = pre->next;
    tail = pre->next;
    for(int i = 0; i < right-left; i++){
        tmp = pre->next;
        pre->next = tail->next;
        tail->next = pre->next->next;
        pre->next->next = tmp;
    }
    return dummy.next;
}