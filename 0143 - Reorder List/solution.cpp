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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode *now = head;
        for(; now; now = now->next) v.push_back(now);
        int i = 0, j = v.size()-1;
        for(; i < j; i++, j--){
            v[i]->next = v[j];
            v[j]->next = v[i+1];
        }
        v[i]->next = nullptr;
    }
};