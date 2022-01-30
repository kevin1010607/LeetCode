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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t = 0;
        ListNode *now = head, **p = &head;
        while(now) now = now->next, t++;
        now = head;
        for(int i = 1; i <= t-n; i++){
            if(i == t-n) p = &(now->next);
            now = now->next;
        }
        *p = now->next;
        delete now;
        return head;
    }
};