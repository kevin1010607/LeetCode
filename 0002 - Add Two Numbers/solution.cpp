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
        int carry = (l1->val+l2->val)/10;
        ListNode *res = new ListNode((l1->val+l2->val)%10), *now = res;
        l1 = l1->next, l2 = l2->next;
        while(l1 || l2){
            if(l1){carry += l1->val; l1 = l1->next;}
            if(l2){carry += l2->val; l2 = l2->next;}
            now->next = new ListNode(carry%10);
            carry /= 10, now = now->next;
        }
        if(carry) now->next = new ListNode(carry);
        return res;
    }
};