/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode p1, p2, *t1 = &p1, *t2 = &p2;
    p1.next = p2.next = NULL;
    while(head){
        if(head->val < x) t1->next = head, t1 = t1->next;
        else t2->next = head, t2 = t2->next;
        head = head->next;
    }
    t1->next = p2.next, t2->next = NULL;
    return p1.next;
}