/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0, n1, n2;
        ListNode *now = head, **p1 = &head, **p2 = &head;
        while(now) now = now->next, n++;
        n1 = k-1, n2 = n-k, now = head;
        for(int i = 1; i <= max(n1, n2); i++){
            if(i == n1) p1 = &(now->next);
            if(i == n2) p2 = &(now->next);
            now = now->next;
        }
        swap(*p1, *p2);
        swap((*p1)->next, (*p2)->next);
        return head;
    }
};