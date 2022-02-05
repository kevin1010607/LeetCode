/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head, **t = &head;
    while(list1 && list2){
        if(list1->val < list2->val) *t = list1, list1 = list1->next;
        else *t = list2, list2 = list2->next;
        t = &((*t)->next);
    }
    *t = list1?list1:list2;
    return head;
}