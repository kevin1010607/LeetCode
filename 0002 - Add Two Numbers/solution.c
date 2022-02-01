/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *newNode(int val){
    struct ListNode *res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->val = val, res->next = NULL;
    return res;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = (l1->val+l2->val)/10;
    struct ListNode *res = newNode((l1->val+l2->val)%10), *now = res;
    l1 = l1->next, l2 = l2->next;
    while(l1 || l2){
        if(l1) {carry += l1->val, l1 = l1->next;}
        if(l2) {carry += l2->val, l2 = l2->next;}
        now->next = newNode(carry%10);
        carry /= 10, now = now->next;
    }
    if(carry) now->next = newNode(carry);
    return res;
}