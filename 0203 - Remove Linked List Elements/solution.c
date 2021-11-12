/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode)), *now = dummy, *tmp;
    dummy->next = head;
    while(now->next){
        if(now->next->val == val){
            tmp = now->next;
            now->next = tmp->next;
            free(tmp);
        }
        else now = now->next;
    }
    tmp = dummy->next;
    free(dummy);
    return tmp;
}