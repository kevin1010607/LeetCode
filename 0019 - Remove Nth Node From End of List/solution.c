/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int t = 0;
    struct ListNode *now = head, **p = &head;
    while(now) now = now->next, t++;
    now = head;
    for(int i = 1; i <= t-n; i++){
        if(i == t-n) p = &(now->next);
        now = now->next;
    }
    *p = now->next;
    free(now);
    return head;
}