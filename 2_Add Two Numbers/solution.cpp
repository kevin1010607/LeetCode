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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode((l1->val+l2->val)%10);
        ListNode *now = ret, *tmp = new ListNode((l1->val+l2->val)/10);
        l1 = l1->next, l2 = l2->next;
        while(l1 || l2){
            int val = tmp->val;
            if(l1){val += l1->val; l1 = l1->next;}
            if(l2){val += l2->val; l2 = l2->next;}
            now->next = new ListNode(val%10);
            tmp->val = val/10;
            now = now->next;
        }
        if(tmp->val != 0) now->next = new ListNode(tmp->val);
        delete tmp;
        return ret;
    }
};
