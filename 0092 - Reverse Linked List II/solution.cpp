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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head), *now = &dummy, *l, *r;
        for(int i = 0; i < left-1; i++) now = now->next;
        l = now, r = now->next, now = now->next->next;
        for(int i = 0; i < right-left; i++){
            r->next = now->next;
            now->next = l->next;
            l->next = now;
            now = r->next;
        }
        return dummy.next;
    }
};