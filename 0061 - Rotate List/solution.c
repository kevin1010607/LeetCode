/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head) return head;
    int n = 1;
    struct ListNode *now = head;
    while(now->next) now = now->next, n++;
    now = now->next = head;
    
    k = (n-1)-(k%n);
    while(k--) now = now->next;
    head = now->next;
    now->next = NULL;
    return head;
}