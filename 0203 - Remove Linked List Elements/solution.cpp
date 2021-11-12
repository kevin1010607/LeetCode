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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **p = &head, *now = head;
        for(; now; now = now->next){
            if(now->val != val){
                *p = now;
                p = &(now->next);
            }
        }
        *p = nullptr;
        return head;
    }
};