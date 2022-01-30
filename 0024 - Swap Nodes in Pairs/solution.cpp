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
    ListNode* swapPairs(ListNode* head) {
        ListNode *d = new ListNode(-1, head), *now = d, *tmp;
        for(; now->next && now->next->next; now = now->next->next){
            tmp = now->next->next;
            now->next->next = tmp->next;
            tmp->next = now->next;
            now->next = tmp;
        }
        return d->next;
    }
};