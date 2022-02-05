/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int n = listsSize;
    struct ListNode *head;
    if(n == 0) head = NULL;
    else if(n == 1) head = lists[0];
    else if(n == 2){
        struct ListNode **t = &head;
        while(lists[0] && lists[1]){
            if(lists[0]->val < lists[1]->val) *t = lists[0], lists[0] = lists[0]->next;
            else *t = lists[1], lists[1] = lists[1]->next;
            t = &((*t)->next);
        }
        *t = lists[0]?lists[0]:lists[1];
    }
    else{
        struct ListNode *s[2];
        s[0] = mergeKLists(lists, n/2);
        s[1] = mergeKLists(lists+n/2, n-n/2);
        head = mergeKLists(s, 2);
    }
    return head;
}