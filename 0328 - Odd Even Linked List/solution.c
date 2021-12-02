/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode *odd = head, *even = head->next, *now = head->next->next, *now1 = odd, *now2 = even;
    int pos = 1;
    while(now){
        if(pos) now1->next = now, now1 = now1->next;
        else now2->next = now, now2 = now2->next;
        now = now->next;
        pos ^= 1;
    }
    now1->next = even;
    now2->next = NULL;
    return odd;
}