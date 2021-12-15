/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode dummy;
    dummy.next = NULL;
    while(head){
        struct ListNode *pre = &dummy, *nxt = head->next;
        while(pre->next && pre->next->val<head->val) pre = pre->next;
        head->next = pre->next;
        pre->next = head;
        head = nxt;
    }
    return dummy.next;
}