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
    struct cmp{bool operator()(ListNode *l1, ListNode *l2){return l1->val>l2->val;}};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, **now = &head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto l : lists) if(l) q.push(l);
        while(!q.empty()){
            ListNode *node = q.top();
            q.pop();
            if(node->next) q.push(node->next);
            *now = node;
            now = &((*now)->next);
        }
        return head;
    }
};