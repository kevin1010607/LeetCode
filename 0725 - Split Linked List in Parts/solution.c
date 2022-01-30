/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    struct ListNode **res = (struct ListNode**)malloc(k*sizeof(struct ListNode*));
    int n = 0;
    struct ListNode *now = head, *tmp = head;
    while(tmp) tmp = tmp->next, n++;
    for(int i = 0; i < k; i++){
        int t = n/k+(bool)(n/k*k+i<n)-1;
        head = now;
        while(t-- && now) now = now->next;
        if(now) tmp = now, now = now->next, tmp->next = NULL;
        res[i] = head;
    }
    *returnSize = k;
    return res;
}