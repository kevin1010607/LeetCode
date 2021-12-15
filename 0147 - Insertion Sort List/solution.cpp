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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> v;
        for(; head; head = head->next) v.push_back(head);
        auto cmp = [](ListNode *l, ListNode *r) {return l->val<r->val;};
        sort(v.begin(), v.end(), cmp);
        for(auto it = v.begin(); it+1 != v.end(); it++)
            (*it)->next = *(it+1);
        v.back()->next = nullptr;
        return v.front();
    }
};