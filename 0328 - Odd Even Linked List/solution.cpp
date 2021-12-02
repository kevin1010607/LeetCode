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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *now = head->next->next, *now1 = odd, *now2 = even;
        int pos = 1;
        while(now){
            if(pos) now1->next = now, now1 = now1->next;
            else now2->next = now, now2 = now2->next;
            now = now->next;
            pos ^= 1;
        }
        now1->next = even;
        now2->next = NULL;
        return odd;
    }
};