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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 1;
        ListNode *now = head;
        while(now->next) now = now->next, n++;
        now = now->next = head;
        
        k = (n-1)-(k%n);
        while(k--) now = now->next;
        head = now->next;
        now->next = nullptr;
        return head;
    }
};