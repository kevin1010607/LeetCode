/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode **p = &head, *now = head;
    for(; now; now = now->next){
        if(now->val != val){
            *p = now;
            p = &(now->next);
        }
    }
    *p = NULL;
    return head;
}