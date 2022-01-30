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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *d = new ListNode(-1, head), *now = head, *tail;
        while(now) now = now->next, n++;
        now = d;
        for(int i = 0; i < n/k; i++){
            head = now, tail = now->next, now = now->next->next;
            for(int j = 0; j < k-1; j++){
                tail->next = now->next;
                now->next = head->next;
                head->next = now;
                now = tail->next;
            }
            now = tail;
        }
        return d->next;
    }
};