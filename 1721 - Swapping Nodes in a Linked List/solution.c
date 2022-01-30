/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define max(a,b) (((a)>(b))?(a):(b))
void swap(struct ListNode **a, struct ListNode **b){
    struct ListNode *tmp = *a; *a = *b, *b = tmp;
}
struct ListNode* swapNodes(struct ListNode* head, int k){
    int n = 0, n1, n2;
    struct ListNode *now = head, **p1 = &head, **p2 = &head, *tmp;
    while(now) now = now->next, n++;
    n1 = k-1, n2 = n-k, now = head;
    for(int i = 1; i <= max(n1, n2); i++){
        if(i == n1) p1 = &(now->next);
        if(i == n2) p2 = &(now->next);
        now = now->next;
    }
    swap(p1, p2);
    swap(&((*p1)->next), &((*p2)->next));
    return head;
}