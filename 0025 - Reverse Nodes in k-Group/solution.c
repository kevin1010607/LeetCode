/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *now = head, *prev, *tmp;
    for(int i = 0; i < k; i++){
        if(!now) return head;
        now = now->next;
    }
    prev = NULL, now = head;
    for(int i = 0; i < k; i++){
        tmp = now->next;
        now->next = prev;
        prev = now;
        now = tmp;
    }
    head->next = reverseKGroup(now, k);
    return prev;
}