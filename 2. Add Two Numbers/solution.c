/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *newNode(int val){
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val, ret->next = NULL;
    return ret;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret = newNode((l1->val+l2->val)%10);
    struct ListNode *now = ret, *tmp = newNode((l1->val+l2->val)/10);
    l1 = l1->next, l2 = l2->next;
    while(l1 || l2){
        int val = tmp->val;
        if(l1) {val += l1->val; l1 = l1->next;}
        if(l2) {val += l2->val; l2 = l2->next;}
        now->next = newNode(val%10);
        tmp->val = val/10;
        now = now->next;
    }
    if(tmp->val != 0) now->next = newNode(tmp->val);
    free(tmp);
    return ret;
}