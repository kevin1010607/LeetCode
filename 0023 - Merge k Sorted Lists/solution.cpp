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
private:
    struct cmp{bool operator()(ListNode *l1, ListNode *l2){return l1->val>l2->val;}};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, **t = &head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto& l : lists) if(l) q.push(l);
        while(!q.empty()){
            *t = q.top(); q.pop();
            if((*t)->next) q.push((*t)->next);
            t = &((*t)->next);
        }
        return head;
    }
};