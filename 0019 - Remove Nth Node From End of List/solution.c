/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast = head, **slow = &head;
    while(fast->next){
        if(--n <= 0) slow = &((*slow)->next);
        fast = fast->next;
    }
    *slow = (*slow)->next;
    return head;
}