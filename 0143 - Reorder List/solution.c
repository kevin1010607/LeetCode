/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    if(!head->next) return;
    struct ListNode *p = head, *q = head, *now, *mid;
    while(q->next && q->next->next){
        p = p->next;
        q = q->next->next;
    }
    now = p->next;
    while(now->next){
        q = now->next, now->next = q->next;
        q->next = p->next, p->next = q;
    }
    mid = p->next, p->next = NULL; 
    while(mid){
        p = head, q = mid;
        head = head->next, mid = mid->next;
        p->next = q, q->next = head;
    }
}