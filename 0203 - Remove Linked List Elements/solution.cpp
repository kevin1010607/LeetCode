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
        ListNode *dummy = new ListNode(0, head), *now = dummy, *tmp;
        while(now->next){
            if(now->next->val == val){
                tmp = now->next;
                now->next = tmp->next;
                delete tmp;
            }
            else now = now->next;
        }
        tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};