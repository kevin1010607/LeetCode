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
    ListNode* partition(ListNode* head, int x) {
        ListNode p1, p2, *t1 = &p1, *t2 = &p2;
        while(head){
            ListNode*& t = head->val<x?t1:t2;
            t->next = head, t = t->next;
            head = head->next;
        }
        t1->next = p2.next, t2->next = nullptr;
        return p1.next;
    }
};